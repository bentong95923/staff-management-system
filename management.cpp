#include "management.h"

System::System(sqlite3 **db)
{
    this->db = db;
    this->setUserInput(INVALID);
}

bool System::run()
{
    bool cont = true, cont2 = true;
    while (cont)
    {
        this->view();
        if (!this->askUserInput())
        {
            cont = false;
            cont2 = false;
        }
        else
        {
            while (cont2)
            {
                cont2 = this->execute();
                cout << cont2 << endl;
            }
        }
    }
    return cont;
}

void System::view()
{
    cout << endl;
    cout << "Welcome to " << ORGANIZATION_NAME << "'s Staff Management System!" << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << endl;
    cout << "Please select the following actions by entering the corresponding number:" << endl;
    cout << "1 - View a staff member's profile" << endl;
    cout << "2 - Edit a staff member's profile" << endl;
    cout << "3 - Create a staff member's profile" << endl;
    cout << "4 - Delete a staff member's profile" << endl;
    cout << "To quit the system, type 'quit'." << endl;
}

bool System::askUserInput()
{
    char s[256];
    bool validInput = false;
    cin.clear();
    while (!validInput)
    {
        cout << "> ";
        cin.getline(s, 256);
        string sss(s);

        // Trim whitespace
        sss = trim(sss);
        istringstream parse(sss);
        if (sss == "quit")
        {
            return false;
            break;
        }
        else if (Validator::validate_positive_integer(sss))
        {
            if (stoi(sss) >= 1 && stoi(sss) <= 4)
            {
                this->setUserInput((ActionSelection)stoi(sss));
                cout << sss << endl;
                validInput = true;
            }
            else
            {
                cout << "Please enter a number corresponding to the actions." << endl;
            }
        }
        else
        {
            cout << "Invalid input. Please try again." << endl;
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