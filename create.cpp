#include "create.h"

Create::Create()
{
    // Initialize user input vector
    vector<string> v(MAX_CREATE_INPUTS, "");
    this->setUserInput(v);
}

void Create::view()
{
    cout << "To create a profile of a staff member, please provide the following details. An asterisk '*' means the field is mandatory." << endl;
    for (int i = 0; i < ALL_FIELDS_TABLE_0.size(); i++)
    {
        cout << i + 1 << ". " << ALL_FIELDS_TABLE_0.at(i);
        if (!VectorExtension::is_element_in_vector(OPTIONAL_FIELDS_TABLE_0, i))
        {
            cout << "*";
        }
        cout << endl;
    }
    cout << "Press 'Enter' when you are ready to input the above information." << endl;
}

void Create::askUserInput()
{
    // As from the menu the user will press 'enter' after selecting one of the operation, thus it needs to ignore previous input to capture the future input
    cin.ignore();
    while (cin.get() != '\n')
        cout << "Please enter the information for each fields which matches it's corresponding numbering:" << endl;
    vector<string> temp = {};
    for (int i = 0; i < MAX_CREATE_INPUTS; i++)
    {
        char s[256];
        bool validInput = false;
        // Optional fields
        if (VectorExtension::is_element_in_vector(OPTIONAL_FIELDS_TABLE_0, i))
        {
            while (!validInput)
            {
                cout << ALL_FIELDS_TABLE_0.at(i) << " : ";
                cin.getline(s, 256);
                //cout << "'" << s << "'" << endl;
                string sss(s);

                // Trim whitespace
                sss = trim(sss);
                istringstream parse(sss);
                // up to here: need to validate input before storing
                if (this->validate_input(sss, i) || sss.size() == 0)
                {
                    temp.push_back(sss);
                    validInput = true;
                }
                else
                {
                    cout << "Input is invalid. Please try again." << endl;
                }
                //cout << "byebye" << endl;
            }
        }
        else
        // Required fields
        {
            while (!validInput)
            {
                cout << ALL_FIELDS_TABLE_0.at(i) << "* : ";
                cin.getline(s, 256);
                // cout << "'" << s << "'" << endl;
                string sss(s);
                while ((trim(sss)).size() == 0)
                {
                    cout << ALL_FIELDS_TABLE_0.at(i) << " is required!" << endl;
                    cout << ALL_FIELDS_TABLE_0.at(i) << "* : ";

                    cin.getline(s, 256);
                    sss = s;
                }
                // Trim whitespace
                sss = trim(sss);
                istringstream parse(sss);
                // up to here: need to validate input before storing
                if (this->validate_input(sss, i))
                {
                    temp.push_back(sss);
                    validInput = true;
                }
                else
                {
                    cout << "Input is invalid. Please try again." << endl;
                }
            }
        }
    }
    cout << endl;
    for (string j : temp)
    {
        cout << j << " " << endl;
    }
    this->setUserInput(temp);
}

bool Create::validate_input(string input, int i)
{
    switch (i)
    {
    case 0:
    case 1:
    case 2:
    case 4:
    case 5:
        return Validator::validate_words_only(input);
        break;
    case 3:
        return Validator::validate_date(input);
        break;
    case 6:
        return Validator::validate_landline(input);
        break;
    case 7:
        return Validator::validate_mobile(input);
        break;
    case 8:
        return Validator::validate_email(input);
        break;
    case 9:
        return Validator::validate_salary(input);
        break;
    default:
        cout << "Error in " << __func__ << ": wrong argument 'i' is given" << endl;
        return false;
        break;
    }
}

void Create::execute(sqlite3 **db)
{
    // Run by sql
    string userInputTemp = "";
    string sql = "INSERT INTO " + TABLE_NAME.at(0) + " (" +
                 VectorExtension::vector_to_string(ALL_FIELDS_TABLE_0, ",") +
                 ") VALUES (" +
                 VectorExtension::vector_to_string(this->getUserInput(), ",") +
                 ")";
    cout << sql << endl;

    char *zErrMsg = 0;
    int rc = sqlite3_exec(*db, sql.c_str(), SQL::sql_callback, 0, &zErrMsg);
    if (rc != SQLITE_OK)
    {
        cerr << "SQL error: " << zErrMsg << endl;
        sqlite3_free(zErrMsg);
    }
    else
    {
        cout << "Staff member's profile created successfully" << endl;
    }
}

vector<string> Create::getUserInput()
{
    return this->userInput;
}
void Create::setUserInput(vector<string> i)
{
    this->userInput = i;
}

Create::~Create()
{
}