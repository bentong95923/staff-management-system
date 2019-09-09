#include "delete.h"

Delete::Delete()
{
    vector<string> v(1, "");
    this->setUserInput(v);
}

void Delete::view()
{
    cout << "WARNING! The profile CANNOT be recovered after it is deleted. It cannot be UNDONE!" << endl;
    cout << "Please enter the ID of the staff member's profile to be deleted: ";
}

bool Delete::askUserInput()
{
    char s[256];
    cin.clear();
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
            return true;
            break;
        }
        else
        {
            cout << "Invalid input. Abort." << endl;
            return false;
            break;
        }
    }
}

bool Delete::execute(sqlite3 **db)
{
    string sql = "select * from " + TABLE_NAME.at(0) + " where ID = '" + this->getUserInput().at(0) + "'";
    char *zErrMsg = 0;
    cout << "looking for staff member's profile with ID " + this->getUserInput().at(0) + "..............................";
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
        if (numResult > 0)
        {
            cout << endl;
            cout << numResult << " Profile found." << endl;
            cout << endl;
            cout << "Are you sure you want to delete the above staff member's profile (LAST CHANCE!) [Y/n]? ";
            char ss[256];
            cin.clear();
            while (true)
            {
                cout << "> ";
                cin.getline(ss, 256);
                string sss(ss);

                // Trim whitespace
                sss = trim(sss);
                istringstream parse(sss);
                if (sss == "Y" || sss == "y")
                {
                    sql = "delete from " + TABLE_NAME.at(0) + " where ID = " + this->getUserInput().at(0);
                    char *zErrMsg = 0;
                    cout << "deleting ..............................";
                    // int numResult = 0;
                    int rc = sqlite3_exec(*db, sql.c_str(), SQL::sql_callback, 0, &zErrMsg);
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
                        cout << "Press ENTER to go back to main menu..." << endl;
                        while (cin.get() != '\n')
                            ;
                        return false;
                    }
                }
                else
                {
                    cout << "Action abort. Profile has not been deleted." << endl;
                    return false;
                    break;
                }
            }
        }
        else
        {
            cout << "no profiles found! Please try again." << endl;
            return true;
        }
    }

    return false;
}

Delete::~Delete()
{
}