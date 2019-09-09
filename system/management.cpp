#include "management.h"

System::System(sqlite3 **db)
{
    this->db = db;
}

void System::run()
{
    while (true)
    {
        this->view();
        if (this->askUserInput())
        {
            while (true)
            {
                if (!this->execute())
                {
                    break;
                }
            }
        }
        else
        {
            break;
        }
    }
}

void System::view()
{
    cout << endl;
    cout << "Welcome to " << ORGANIZATION_NAME << "'s Staff Management System!" << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "Please enter the number which corresponding to the following operation:" << endl;
    cout << "1 - View staff member's profiles" << endl;
    cout << "2 - Edit staff member's profiles" << endl;
    cout << "3 - Create staff member's profiles" << endl;
    cout << "4 - Delete staff member's profiles" << endl;
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
            if (stoi(sss) >= (int)VIEW && stoi(sss) <= (int)DELETE)
            {
                this->setUserInput((ActionSelection)stoi(sss));
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
        View *op = new View();
        op->view();
        if (!op->askUserInput())
        {
            return false;
        }
        else
        {
            return op->execute(this->db);
        }
        break;
    }
    case EDIT:
    {
        Edit *op = new Edit();
        op->view();
        if (!op->askUserInput())
        {
            return false;
        }
        else
        {
            return op->execute(this->db);
        }
        break;
    }
    case CREATE:
    {
        Create *op = new Create();
        op->view();
        if (!op->askUserInput())
        {
            return false;
        }
        else
        {
            return op->execute(this->db);
        }
        break;
    }
    case DELETE:
    {
        Delete *op = new Delete();
        op->view();
        if (!op->askUserInput())
        {
            return false;
        }
        else
        {
            return op->execute(this->db);
        }
        break;
    }

    default:
    {
        cout << "Invalid operation!" << endl;
        return false;
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