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
    for (int i = 0; i < ALL_FIELD_CREATE.size(); i++)
    {
        cout << i + 1 << ". " << ALL_FIELD_CREATE.at(i);
        if ((find(OPTIONAL_FIELD_CREATE.begin(), OPTIONAL_FIELD_CREATE.end(), i)) != OPTIONAL_FIELD_CREATE.end())
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
        ;
    cout << "Please enter the information for each fields which matches it's corresponding numbering:" << endl;
    vector<string> temp(MAX_CREATE_INPUTS, "");
    for (int i = 0; i < temp.size(); i++)
    {
        char *s;
        cout << ALL_FIELD_CREATE.at(i) << ": ";
        // Optional
        if ((find(OPTIONAL_FIELD_CREATE.begin(), OPTIONAL_FIELD_CREATE.end(), i)) != OPTIONAL_FIELD_CREATE.end())
        {
            cin.getline(s, 256);
        }
        else
        // Required
        {
            cin.getline(s,256);
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            // Up to here
        }
        // cout << "i: " << i << endl;
        // cin.getline(s, 256);
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