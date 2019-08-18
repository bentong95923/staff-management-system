#include "menu.h"

Menu::Menu()
{
    this->setUserInput(INVALID);
    this->view();
    this->askUserInput();
    this->execute();
}

void Menu::view()
{
    cout << "Welcome to " << ORGANIZATION_NAME << "'s Staff Management System!" << endl;
    cout << endl;
    cout << "Please select the following actions by entering the corresponding number, then hit 'Enter'." << endl;
    cout << "1. View a staff member's profile" << endl;
    cout << "2. Edit a staff member's profile" << endl;
    cout << "3. Create a staff member's profile" << endl;
    cout << "4. Delete a staff member's profile" << endl;
}

void Menu::askUserInput()
{
    int selection = 0;
    cin >> selection;
    this->setUserInput((MenuSelection)selection);
}

void Menu::execute()
{
    switch (this->getUserInput())
    {
    case VIEW:
    {
        /* code */
        cout << "bye" << endl;
        break;
    }
    case EDIT:
    {
        /* code */
        cout << "bye" << endl;
        break;
    }
    case CREATE:
    {
        Create *op = new Create();
        cout <<"hihi"<<endl;
        op->view();
        op->askUserInput();
        break;
    }
    case DELETE:
    {
        /* code */
        cout << "hi" << endl;
        break;
    }

    default:
    {
        cout << "byebye" << endl;
        break;
    }
    }
}

MenuSelection Menu::getUserInput()
{
    return this->userInput;
}

void Menu::setUserInput(MenuSelection s)
{
    this->userInput = s;
}

Menu::~Menu()
{
}