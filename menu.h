#ifndef MENU_H_
#define MENU_H_

#include <iostream>
#include "create.h"
#include "conf.h"

using namespace std;

enum MenuSelection
{
    VIEW = 1,
    EDIT,
    CREATE,
    DELETE
};

class Menu
{
private:
    int userInput;

public:
    Menu();
    ~Menu();
    void view();
    void askUserInput();
    void execute();
    int getUserInput();
    void setUserInput(int s);
};

#endif