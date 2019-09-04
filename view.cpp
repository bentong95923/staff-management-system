#include "view.h"

View::View()
{
    // Initialize user input vector
    vector<string> v(AVAILABLE_SEARCH_FIELD_TABLE_0.size() + 1, "");
    this->setUserInput(v);
}

void View::view()
{
    cout << "Please provide ONLY one of the following information to look up a staff member's profile:" << endl;
    cout << "- ID " << endl;
    for (int j = 0; j < ALL_FIELDS_TABLE_0.size(); j++)
    {
        if (VectorExtension::is_element_in_vector(AVAILABLE_SEARCH_FIELD_TABLE_0, j))
        {
            cout << "- " << ALL_FIELDS_TABLE_0.at(j) << endl;
        }
    }
    cout << "Press ENTER to start searching, or type 'menu' to go back to main menu." << endl;
}

bool View::askUserInput()
{
    char s[256];
    while (true)
    {
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
        else if (Validator::validate_positive_integer(sss)) // validate input
        {
            cout << "Type of information you entered: ID" << endl;
            return true;
        }
        else if (Validator::validate_words_only(sss)) // validate input
        {
            cout << "Type of information you entered: First_Name" << endl;
            return true;
        }
        else if (Validator::validate_date(sss)) // validate input
        {
            cout << "Type of information you entered: Date" << endl;
            return true;
        }
        else if (Validator::validate_email(sss)) // validate input
        {
            cout << "Type of information you entered: Email" << endl;
            return true;
        }
        else
        {
            cout << "Input is invalid. Please try again." << endl;
        }
    }
    return false;
}

bool View::execute(sqlite3 **db)
{
    return false;
}

View::~View()
{
}