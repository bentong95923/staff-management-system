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
    // cout << (cin.get() == '\n') << endl;
    while (cin.get() != '\n')
        ;
    // cout << (cin.get() == '\n') << endl;
    cout << "Please enter the information for each fields which matches it's corresponding numbering:" << endl;
    vector<string> temp(MAX_CREATE_INPUTS, "");
    // vector<int>op_field = OPTIONAL_FIELD;
    for (int i = 0; i < temp.size(); i++)
    {
        // cout << (cin.get() == '\n') << endl;
        cout << i + 1 << ". " << ((find(OPTIONAL_FIELD.begin(), OPTIONAL_FIELD.end(), i)) != OPTIONAL_FIELD.end()) << endl;
        cout << "getting input" << endl;
        if ((find(OPTIONAL_FIELD.begin(), OPTIONAL_FIELD.end(), i)) != OPTIONAL_FIELD.end())
        {
            cin.ignore();
            // char hihi[256];
            string s;
            getline(cin, s);
            // Trim whitespace
            s = trim(s);
            // Space to Underscore
            for (int i = 0; i < s.length(); i++)
            {
                if (s.at(i) == ' ')
                {
                    s.at(i) = '_';
                }
            }
            temp.at(i) = s;
            continue;
        }
        // cout << (cin.get() == '\n') << endl;
        string s;
        cin.ignore();
        cin >> s;

        // Trim whitespace
        s = trim(s);
        // Space to Underscore
        for (int i = 0; i < s.length(); i++)
        {
            if (s.at(i) == ' ')
            {
                s.at(i) = '_';
            }
        }
        cout << s << endl;
        temp.at(i) = s;
    }
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