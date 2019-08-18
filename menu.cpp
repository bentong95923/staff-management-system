#include "menu.h"

Menu::Menu() {

}

void Menu::view() {
    cout << "Welcome to "<< ORGANIZATION_NAME << "'s Staff Management System!" << endl;
    cout << endl;
    cout << "Please select the following actions by entering the corresponding number, then hit 'Enter'." << endl;
    cout << "1. View a staff member's profile" << endl;
    cout << "2. Edit a staff member's profile" << endl;
    cout << "3. Create a staff member's profile" << endl;
    cout << "4. Delete a staff member's profile" << endl;
}

void Menu::askUserInput() {
    int selection = 0;
    cin >> selection;
    this->setUserInput(selection);
}

void Menu::execute() {
    switch (this->getUserInput())
    {
    case VIEW:
        /* code */
        break;
    case EDIT:
        /* code */
        break;
    case CREATE:
        Create *op = new Create();
        op->askUserInput();
        break;
    case DELETE:
        /* code */
        break;

    default:
        break;
    }
}

int Menu::getUserInput() {
    return this->userInput;
}

void Menu::setUserInput(int s) {
    this->userInput = s;
}

Menu::~Menu() {

}