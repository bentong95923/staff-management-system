#include "view.h"

View::View()
{
    // Initialize user input vector
    vector<string> v(2, "");
    this->setUserInput(v);
}

void View::view()
{
    cout << "To look up a profile, you will need to provide one of the following:" << endl;
    cout << "- ID " << endl;
    for (int j = 0; j < ALL_FIELDS_TABLE_0.size(); j++)
    {
        if (VectorExtension::is_element_in_vector(AVAILABLE_SEARCH_FIELD_TABLE_0, j))
        {
            cout << "- " << ALL_FIELDS_TABLE_0.at(j) << endl;
        }
    }
}

bool View::askUserInput()
{
    char s[256];
    while (true)
    {
        cout << "Enter one of the above and press ENTER to start searching, or type 'menu' to go back to main menu." << endl;
        cout << "> ";
        cin.getline(s, 256);
        string sss(s);

        // Trim whitespace
        sss = trim(sss);
        istringstream parse(sss);
        if (sss.size() == 0)
        {
            cout << "Information is required to look up a profile!" << endl;
        }
        else if (sss == "menu")
        {
            return false;
            break;
        }
        else
        {
            cout << "Guessing the type of information you provided is..........";

            vector<string> temp = {};
            if (Validator::validate_positive_integer(sss))
            {
                cout << "ID!" << endl;
                temp.push_back("ID");
                temp.push_back(sss);
                this->setUserInput(temp);
                break;
            }
            else if (Validator::validate_words_only(sss))
            {
                cout << "First_Name!" << endl;
                temp.push_back("First_Name");
                temp.push_back(sss);
                this->setUserInput(temp);
                break;
            }
            else if (Validator::validate_date(sss))
            {
                cout << "DOB!" << endl;
                temp.push_back("DOB");
                temp.push_back(sss);
                this->setUserInput(temp);
                break;
            }
            else if (Validator::validate_email(sss))
            {
                cout << "Email!" << endl;
                temp.push_back("Email");
                temp.push_back(sss);
                this->setUserInput(temp);
                break;
            }
            else
            {
                cout << "Invalid!" << endl;
                cout << "Please try again." << endl;
            }
        }
    }
    return true;
}

bool View::execute(sqlite3 **db)
{
    // Run by sql
    string userInputTemp = "";
    string sql = "select * from " + TABLE_NAME.at(0) + " where " + this->getUserInput().at(0) + "='" + this->getUserInput().at(1)+"'";
    
    char *zErrMsg = 0;
    cout << "looking for staff member's profile with " + this->getUserInput().at(0) + " " + this->getUserInput().at(1) + "..............................";
    int rc = sqlite3_exec(*db, sql.c_str(), SQL::sql_callback, 0, &zErrMsg);
    if (rc != SQLITE_OK)
    {
        cout << "fail!" << endl;
        cerr << "SQL error: " << zErrMsg << endl;
        sqlite3_free(zErrMsg);
    }
    else
    {
        cout << "Profile(s) found!" << endl;
    }
    char s[256];
    while (true)
    {
        cout << "Type 'menu' to go back to main menu, or press ENTER to view other staff memeber's profile." << endl;
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

View::~View()
{
}