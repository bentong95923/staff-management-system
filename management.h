#ifndef MANAGEMENT_H_
#define MANAGEMENT_H_

#include <iostream>
#include "sqlite/sqlite3.h"
#include "create.h"

using namespace std;

enum ActionSelection
{
    INVALID = 0,
    VIEW,
    EDIT,
    CREATE,
    DELETE
};

class System
{
private:
    ActionSelection userInput;
protected:
    sqlite3 **db;
public:
    System(sqlite3 **db);
    ~System();
    bool run();
    void view();
    bool askUserInput();
    bool execute();
    ActionSelection getUserInput();
    void setUserInput(ActionSelection s);
};

#endif