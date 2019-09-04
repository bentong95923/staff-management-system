#include "view.h"

View::View()
{
    // Initialize user input vector
    vector<string> v(AVAILABLE_SEARCH_FIELD_TABLE_0.size() + 1, "");
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
            enum DataType
            {
                ID,
                WORDS,
                DATE,
                EMAIL,
                INVALID
            };

            DataType type;

            Validator::validate_positive_integer(sss) ? type = ID : Validator::validate_words_only(sss) ? type = WORDS : Validator::validate_date(sss) ? type = DATE : Validator::validate_email(sss) ? type = EMAIL : type = INVALID;
            string sql = "select * from " + TABLE_NAME.at(0) + " where "; // select * from Staff_Details where id = 2
            
            switch (type)
            {
            case ID:
                cout << "Guessing information you provide is ID.........." << endl;
                break;
            case WORDS:
                cout << "Guessing information you provide is First_Name.........." << endl;
                break;
            case DATE:
                cout << "Guessing information you provide is Date.........." << endl;
                break;
            case EMAIL:
                cout << "Guessing information you provide is Email.........." << endl;
                break;
            default:
                cout << "Input is invalid. Please try again." << endl;
                break;
            }
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