#include "management.h"

System::System(sqlite3 **db)
{
    this->db = db;
    this->setUserInput(INVALID);
}

bool System::run()
{
    this->view();
    bool success;
    this->askUserInput() ? success = this->execute() : success = false;
    return success;
}

void System::view()
{
    cout << "Welcome to " << ORGANIZATION_NAME << "'s Staff Management System!" << endl;
    cout << endl;
    cout << "Please select the following actions by entering the corresponding number, then press ENTER." << endl;
    cout << "1 - View a staff member's profile" << endl;
    cout << "2 - Edit a staff member's profile" << endl;
    cout << "3 - Create a staff member's profile" << endl;
    cout << "4 - Delete a staff member's profile" << endl;
    cout << "If you want to quit the system, type 'quit' (case insensitive) and press ENTER." << endl;
}

bool System::askUserInput()
{
    char s[256];
    bool validInput = false;
    while (!validInput)
    {
        cout << "Selection : ";
        cin.getline(s, 256);
        string sss(s);

        // Trim whitespace
        sss = trim(sss);
        istringstream parse(sss);
        // convert string to to lower case
        for (int x = 0; x < sss.size(); x++)
        {
            sss.at(x) = tolower(sss.at(x));
        }
        if (s == "quit")
        {
            return false;
        }
        else if (Validator::validate_positive_integer(s))
        {
            if (stoi(s) >= 1 || stoi(s) <= 4)
            {
                this->setUserInput((ActionSelection)stoi(s));
                validInput = true;
            }
            else
            {
                cout << "Please enter a number which corresponding to the actions." << endl;
            }
        }
        else
        {
            cout << "Please enter a number." << endl;
        }
    }
    return validInput;
}

bool System::execute()
{
    switch (this->getUserInput())
    {
    case VIEW:
    {
        /* code */
        cout << "View" << endl;
        break;
    }
    case EDIT:
    {
        /* code */
        cout << "Edit" << endl;
        break;
    }
    case CREATE:
    {
        Create *op = new Create();
        op->view();
        bool quit = !op->askUserInput();
        if (quit)
        {
            return quit;
        }
        else
        {
            return op->execute(this->db);
        }
        break;
    }
    case DELETE:
    {
        /* code */
        cout << "Delete" << endl;
        break;
    }

    default:
    {
        cout << "byebye" << endl;
        break;
    }
    }
}

ActionSelection System::getUserInput()
{
    return this->userInput;
}

void System::setUserInput(ActionSelection s)
{
    this->userInput = s;
}

System::~System()
{
}