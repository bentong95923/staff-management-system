#include "edit.h"
#include "create.h"

Edit::Edit()
{
    vector<string> v(1, "");
    this->setUserInput(v);
}

void Edit::view()
{
    cout << "Please enter the ID of the staff member's profile to be edited, or type 'menu' to go back to main menu." << endl;
    cout << "> ";
}

bool Edit::askUserInput()
{
    char s[256];
    while (true)
    {
        cin.getline(s, 256);
        string sss(s);

        // Trim whitespace
        sss = trim(sss);
        istringstream parse(sss);
        if (Validator::validate_positive_integer(sss))
        {
            vector<string> temp(1, sss);
            this->setUserInput(temp);
            break;
        }
        else if (sss == "menu")
        {
            return false;
            break;
        }
        else
        {
            cout << "Input is invalid. Please try again." << endl;
            this->view();
        }
    }
    return true;
}

bool Edit::execute(sqlite3 **db)
{
    // Run by sql
    string sql = "select * from " + TABLE_NAME.at(0) + " where id = '" + this->getUserInput().at(0) + "'";

    char *zErrMsg = 0;
    cout << "looking for staff member's profile(s) with ID " + this->getUserInput().at(0) + "..............................";
    int numResult = 0;
    int rc = sqlite3_exec(*db, sql.c_str(), SQL::sql_callback, &numResult, &zErrMsg);
    if (rc != SQLITE_OK)
    {
        cout << "fail!" << endl;
        cerr << "SQL error: " << zErrMsg << endl;
        sqlite3_free(zErrMsg);
    }
    else
    {
        if (numResult > 0)
        {
            cout << endl;
            cout << "Profile found." << endl;
        }
        else
        {
            cout << "no profiles found!" << endl;
            cout << "Please try again." << endl;
            return true;
        }
        cout << endl;
    }

    char s[256];
    while (true)
    {
        cout << "Type 'edit' to edit this profile." << endl;
        cout << "Type 'menu' to go back to main menu." << endl;
        cout << "Press ENTER to view/edit other staff memeber's profile." << endl;
        cout << "> ";
        cin.getline(s, 256);
        string sss(s);

        // Trim whitespace
        sss = trim(sss);
        istringstream parse(sss);
        if (sss == "menu")
        {
            return false;
            break;
        }
        else if (sss == "edit")
        {
            return this->edit(db);
        }
        else if (sss.size() == 0)
        {
            return true;
            break;
        }
        else
        {
            cout << "Input is invalid. Please try again." << endl;
        }
    }
}

bool Edit::edit(sqlite3 **db)
{
    vector<string> temp(ALL_FIELDS_TABLE_0.size(), "");
    bool editCompleted = false;
    while (!editCompleted)
    {
        int i = 0;
        char sedit[256];
        while (true)
        {
            cout << "Please enter the field (case sensitive) to edit for this profile (ID: " << this->getUserInput().at(0) << ")." << endl;
            cout << "e.g. 'First_Name' for editing First Name." << endl;
            cout << "> ";
            cin.getline(sedit, 256);
            string sss(sedit);

            // Trim whitespace
            sss = trim(sss);
            istringstream parse(sss);
            if (VectorExtension::is_element_in_vector(ALL_FIELDS_TABLE_0, sss))
            {
                for (i = 0; i < ALL_FIELDS_TABLE_0.size(); i++)
                {
                    if (sss == ALL_FIELDS_TABLE_0.at(i))
                    {
                        break;
                    }
                }
                break;
            }
            else if (sss == "menu")
            {
                return false;
                break;
            }
            else
            {
                cout << "Sorry, the field name you entered does not match in the system. Please try again." << endl;
            }
        }
        bool editing = true;
        while (editing)
        {
            cout << "Please enter " << ALL_FIELDS_TABLE_0.at(i) << " for this staff member." << endl;
            cout << "> ";
            cin.getline(sedit, 256);
            string sss(sedit);

            // Trim whitespace
            sss = trim(sss);
            istringstream parse(sss);
            if (Validator::validate_input_by_index(sss, i))
            {
                temp[i] = sedit;
                char sedit2[256];
                while (true)
                {
                    cout << "Saved locally!" << endl;
                    cout << "Press ENTER to continue editing other field of this profile." << endl;
                    cout << "Type 'done' to finish and preview the changes (CANNOT be undone)." << endl;
                    cout << "Type 'menu' to undo the change and go back to menu." << endl;
                    cout << "> ";
                    cin.getline(sedit2, 256);
                    string sss(sedit2);

                    // Trim whitespace
                    sss = trim(sss);
                    istringstream parse(sss);
                    if (sss.size() == 0)
                    {
                        editing = false;
                        break;
                    }
                    else if (sss == "done")
                    {
                        editing = false;
                        editCompleted = true;
                        break;
                    }
                    else if (sss == "menu")
                    {
                        return false;
                    }
                    else
                    {
                        cout << "Invalid input. Please try again." << endl;
                    }
                }
            }
            else
            {
                cout << "Input is invalid. Please try again." << endl;
            }
        }
    }

    cout << "Field(s) to be changed for the profile (ID: " << this->getUserInput().at(0) << "):" << endl;

    for (int j = 0; j < ALL_FIELDS_TABLE_0.size(); j++)
    {
        if (temp.at(j).size() > 0)
        {
            cout << ALL_FIELDS_TABLE_0.at(j) << ": " << temp.at(j) << endl;
        }
    }

    cout << "Press ENTER to write the above change to database...";

    while (cin.get() != '\n')
        ;

    string sqlColValues = "";
    for (int k = 0; k < ALL_FIELDS_TABLE_0.size(); k++)
    {
        if (temp.at(k).size() != 0)
        {
            sqlColValues += ALL_FIELDS_TABLE_0.at(k) + " = '" + temp.at(k) + "',";
        }
    }
    if (sqlColValues.size() > 0)
    {
        if (sqlColValues.at(sqlColValues.size() - 1) == ',')
        {
            sqlColValues.at(sqlColValues.size() - 1) = ' ';
        }
    }

    string sql = "update " + TABLE_NAME.at(0) + " set " + sqlColValues + " where ID = '" + this->getUserInput().at(0) + "'";
    char *zErrMsg = 0;
    cout << "writing changes to database..............................";
    int numResult = 0;
    int rc = sqlite3_exec(*db, sql.c_str(), SQL::sql_callback, &numResult, &zErrMsg);
    if (rc != SQLITE_OK)
    {
        cout << "fail!" << endl;
        cerr << "SQL error: " << zErrMsg << endl;
        sqlite3_free(zErrMsg);
        return false;
    }
    else
    {
        cout << "success!" << endl;
        cout << "Press ENTER to view/edit another profile, or type 'menu' to go back to main menu." << endl;
        cout << "> ";
        char sedit3[256];
        cin.getline(sedit3, 256);
        string sss(sedit3);
        // Trim whitespace
        sss = trim(sss);
        istringstream parse(sss);
        if (sss.size() == 0)
        {
            return true;
        }
        else if (sss == "menu")
        {
            return false;
        }
        else
        {
            cout << "Invalid input, returning to main menu." << endl;
            return false;
        }
    }
}

Edit::~Edit() {}