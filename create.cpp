#include "create.h"

Create::Create()
{
    // Initialize user input vector
    vector<string> v(MAX_CREATE_INPUTS, "");
    this->setUserInput(v);
}

void Create::view()
{
    cout << "To create a profile of a staff member, it requires at least the following unless it is optional:" << endl;
    for (int i = 0; i < ALL_FIELDS_TABLE_0.size(); i++)
    {
        cout << i + 1 << ". " << ALL_FIELDS_TABLE_0.at(i);
        if (VectorExtension::is_element_in_vector(OPTIONAL_FIELDS_TABLE_0, i))
        {
            cout << " (optional)";
        }
        cout << endl;
    }
    cout << "Press 'Enter' when you are ready to input the above information. Leave blank if you do not have any information for optional fields." << endl;
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
        cout << ALL_FIELDS_TABLE_0.at(i) << ": ";
        cout << "i: " << i << endl;
        // Optional
        // vector<int>::iterator it = find(OPTIONAL_FIELD_CREATE.begin(), OPTIONAL_FIELD_CREATE.end(), i);
        if (VectorExtension::is_element_in_vector(OPTIONAL_FIELDS_TABLE_0, i))
        {
            cout << "optional" << endl;
            cin.getline(s, 256);
            cout << "'" << s << "'" << endl;
            string sss(s);

            // Trim whitespace
            sss = trim(sss);
            istringstream parse(sss);
            cout << "hihihihihi" << endl;
            temp.push_back(sss);
            cout << "byebye" << endl;
        }
        else
        // Required
        {
            cout << "required" << endl;
            cin.getline(s, 256);
            cout << "'" << s << "'" << endl;
            string sss(s);
            while ((trim(sss)).size() == 0)
            {
                cout << "hihi" << endl;
                cin.getline(s, 256);
                sss = s;
            }
            // Trim whitespace
            sss = trim(sss);
            istringstream parse(sss);
            cout << "hihihihihi" << endl;
            temp.push_back(sss);
            cout << "byebye" << endl;
        }
    }
    cout << endl;
    for (string j : temp)
    {
        cout << j << " " << endl;
    }
    this->setUserInput(temp);
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