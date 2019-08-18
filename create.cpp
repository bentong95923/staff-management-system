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
    cout << "Press 'Enter' when you are ready to input the above information. Leave blank \\
    if you do not have any information for optional fields." << endl;
}

void Create::askUserInput()
{
    vector<string> temp(MAX_CREATE_INPUTS, "");
    cout << "Please enter the information for each fields which matches it's corresponding numbering:" << endl;
    for (int i = 0; i < temp.size(); i++)
    {
        cout << i << ". " << endl;
        cin >> temp.at(i);
    }
    for (string j:temp) {
        cout << j << " " << endl;
    }
    this->setUserInput(temp);
}

void Create::execute() {
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