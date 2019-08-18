#ifndef MENU_H_
#define MENU_H_

#include <iostream>
#include "create.h"
#include "conf.h"

using namespace std;

enum MenuSelection
{
    INVALID = 0,
    VIEW,
    EDIT,
    CREATE,
    DELETE
};

class Menu
{
private:
    MenuSelection userInput;

public:
    Menu();
    ~Menu();
    void view();
    void askUserInput();
    void execute();
    MenuSelection getUserInput();
    void setUserInput(MenuSelection s);
};

#endif