#include "view.h"

View::View()
{
    // Initialize user input vector
    vector<string> v(2, "");
    this->setUserInput(v);
}

void View::view()
{
    cout << "To view/edit a profile, you will need to provide one of the following:" << endl;
    cout << "- ID " << endl;
    cout << "- " << FIRST_NAME_FIELD << endl;
    cout << "- " << DOB_FIELD << endl;
    cout << "- " << EMAIL_FIELD << endl;
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
                cout << FIRST_NAME_FIELD << "!" << endl;
                temp.push_back(ALL_FIELDS_TABLE.at(0));
                temp.push_back(sss);
                this->setUserInput(temp);
                break;
            }
            else if (Validator::validate_date(sss))
            {
                cout << DOB_FIELD << "!" << endl;
                temp.push_back(ALL_FIELDS_TABLE.at(3));
                temp.push_back(sss);
                this->setUserInput(temp);
                break;
            }
            else if (Validator::validate_email(sss))
            {
                cout << EMAIL_FIELD << "!" << endl;
                temp.push_back(ALL_FIELDS_TABLE.at(8));
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
    string sql = "select * from " + TABLE_NAME + " where " + this->getUserInput().at(0) + "='" + this->getUserInput().at(1) + "'" + "collate nocase";

    char *zErrMsg = 0;
    cout << "Looking for staff member's profile(s) with " + this->getUserInput().at(0) + " " + this->getUserInput().at(1) + "..............................";
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
            string s = numResult > 1 ? "s" : "";
            cout << numResult << " profile" + s + " found." << endl;
        }
        else
        {
            cout << "no profiles found!" << endl;
        }
        cout << endl;
    }

    char s[256];
    while (true)
    {
        cout << "Type 'menu' to go back to main menu, or press ENTER to view/edit other staff memeber's profile." << endl;
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