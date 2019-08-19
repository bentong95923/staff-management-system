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
    cout << "1. First Name" << endl;
    cout << "2. Middle Name (optional)" << endl;
    cout << "3. Last Name" << endl;
    cout << "4. Date of Birth (optional)" << endl;
    cout << "5. Title" << endl;
    cout << "6. Department" << endl;
    cout << "7. Landline (optional)" << endl;
    cout << "8. Email" << endl;
    cout << "9. Salary (optional)" << endl;
    cout << "Press 'Enter' when you are ready to input the above information. Leave blank if you do not have any information for optional fields." << endl;
}

void Create::askUserInput()
{
    // As from the menu the user will press 'enter' after selecting one of the operation, thus it needs to ignore previous input to capture the future input
    cin.ignore();
    while (cin.get() != '\n')
        ;
    cout << "Please enter the information for each fields which matches it's corresponding numbering:" << endl;
    vector<string> temp(MAX_CREATE_INPUTS, "");
    for (int i = 0; i < temp.size(); i++)
    {
        char *s = "";
        cout << ALL_FIELD_CREATE.at(i) << ": ";
        if ((find(OPTIONAL_FIELD_CREATE.begin(), OPTIONAL_FIELD_CREATE.end(), i)) != OPTIONAL_FIELD_CREATE.end())
        {
            cin.getline(s, 256);
        }
        else
        {
            string str(s);
            // cout << (trim(str).size()) << endl;
            /* while (trim(str).size() == 0)
            {
                cout << "cannot be empty" << endl;
                cin.getline(s, 256);
                str = s;
                // cin >> s;
            } */
        }

        // cout << "i: " << i << endl;

        string sss(s);
        // Trim whitespace
        sss = trim(sss);
        istringstream parse(sss);
        temp.at(i) = sss;
    }
    cout << endl;
    for (string j : temp)
    {
        cout << j << " " << endl;
    }
    this->setUserInput(temp);
}

void Create::execute()
{
    // Run by sql
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