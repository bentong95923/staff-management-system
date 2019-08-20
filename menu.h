#ifndef MENU_H_
#define MENU_H_

#include <iostream>
#include "sqlite/sqlite3.h"
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
protected:
    sqlite3 **db;
public:
    Menu(sqlite3 **db);
    ~Menu();
    void view();
    void askUserInput();
    void execute();
    MenuSelection getUserInput();
    void setUserInput(MenuSelection s);
};

#endif