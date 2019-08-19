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
        if (is_element_in_vector(OPTIONAL_FIELD_CREATE, i))
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
    vector<string> temp = {};
    for (int i = 0; i < MAX_CREATE_INPUTS; i++)
    {
        char *s;
        cout << ALL_FIELD_CREATE.at(i) << ": ";
        cout << "i: " << i << endl;
        /* bool optional_field
        for (int x : OPTIONAL_FIELD_CREATE)
        {
            if (x == i) {

            }
        } */
        // Optional
        // vector<int>::iterator it = find(OPTIONAL_FIELD_CREATE.begin(), OPTIONAL_FIELD_CREATE.end(), i);
        if (is_element_in_vector(OPTIONAL_FIELD_CREATE, i))
        {
            cout << "optional" << endl;
            cin.getline(s, 256);
        }
        else
        // Required
        {
            cout << "required" << endl;
            cin.getline(s, 256);
            string ttt(s);
            while ((trim(ttt)).size() == 0)
            {
                // cout << "hihi" << endl;
                cin.getline(s, 256);
                ttt = s;
                // Still have problem
            }
        }
        string sss(s);

        // Trim whitespace
        sss = trim(sss);
        istringstream parse(sss);
        temp.push_back(sss);

        // cout << "hihihihihi" << endl;
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