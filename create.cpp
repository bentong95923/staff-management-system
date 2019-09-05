#include "create.h"

Create::Create()
{
    // Initialize user input vector
    vector<string> v(ALL_FIELDS_TABLE_0.size(), "");
    this->setUserInput(v);
}

void Create::view()
{
    cout << "Please provide the details below to create a new profile."
         << "'*' means mandatory" << endl;

    for (int i = 0; i < ALL_FIELDS_TABLE_0.size(); i++)
    {
        cout << i + 1 << ". " << ALL_FIELDS_TABLE_0.at(i);
        if (!VectorExtension::is_element_in_vector(OPTIONAL_FIELDS_TABLE_0, i))
        {
            cout << "*";
        }
        cout << endl;
    }
}

bool Create::askUserInput()
{
    char s[256];
    while (true)
    {
        cout << "Press ENTER when you are ready, or type 'menu' to go back to main menu." << endl;
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
            break;
        }
        else
        {
            cout << "Input is invalid. Please try again." << endl;
        }
    }
    vector<string> temp = {};
    for (int i = 0; i < ALL_FIELDS_TABLE_0.size(); i++)
    {
        // Optional fields
        if (VectorExtension::is_element_in_vector(OPTIONAL_FIELDS_TABLE_0, i))
        {
            while (true)
            {
                cout << ALL_FIELDS_TABLE_0.at(i) << " : ";
                cin.getline(s, 256);
                string sss(s);

                // Trim whitespace
                sss = trim(sss);
                istringstream parse(sss);
                if (this->validateInput(sss, i) || sss.size() == 0)
                {
                    temp.push_back(sss);
                    break;
                }
                else
                {
                    cout << "Input is invalid. Please try again." << endl;
                }
            }
        }
        else
        // Required fields
        {
            while (true)
            {
                cout << ALL_FIELDS_TABLE_0.at(i) << "* : ";
                cin.getline(s, 256);
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
                if (this->validateInput(sss, i))
                {
                    temp.push_back(sss);
                    break;
                }
                else
                {
                    cout << "Input is invalid. Please try again." << endl;
                }
            }
        }
    }
    cout << endl
         << "Below information summarizes the details you have entered:" << endl;
    for (int j = 0; j < temp.size(); j++)
    {
        cout << ALL_FIELDS_TABLE_0.at(j) << ": " << temp.at(j) << " " << endl;
    }
    cout << "The system will create the profile with the above information. Press ENTER to continue ...";
    while (cin.get() != '\n')
        ;
    this->setUserInput(temp);
    return true;
}

bool Create::validateInput(string input, int i)
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
        return Validator::validate_positive_integer(input);
        break;
    default:
        cerr << "Error in " << __func__ << ": wrong argument 'i' is given" << endl;
        return false;
        break;
    }
}

bool Create::execute(sqlite3 **db)
{
    // Run by sql
    string userInputTemp = "";
    string sql = "insert into " + TABLE_NAME.at(0) + " (" +
                 VectorExtension::vector_to_string(ALL_FIELDS_TABLE_0, ",") +
                 ") values (" +
                 VectorExtension::vector_to_string(this->getUserInput(), ",") +
                 ")";

    char *zErrMsg = 0;
    cout << "creating ..............................";
    int rc = sqlite3_exec(*db, sql.c_str(), SQL::sql_callback, 0, &zErrMsg);
    if (rc != SQLITE_OK)
    {
        cout << "fail!" << endl;
        cerr << "SQL error: " << zErrMsg << endl;
        sqlite3_free(zErrMsg);
    }
    else
    {
        cout << "success!" << endl;
    }

    cout << "The profile for staff member '" << this->getUserInput().at(0) << "' has been created successfully." << endl;

    char s[256];
    while (true)
    {
        cout << "Type 'menu' to go back to main menu, or press ENTER to create another staff memeber's profile." << endl;
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

Create::~Create()
{
}