#ifndef MANAGEMENT_H_
#define MANAGEMENT_H_

#include "../sqlite/sqlite3.h"
#include "../action/view.h"
#include "../action/edit.h"
#include "../action/create.h"
#include "../action/delete.h"

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
    int numRecord;
public:
    System(sqlite3 **db);
    ~System();
    void run();
    void view();
    void retrieveDatabaseRecords();
    bool askUserInput();
    bool execute();
    ActionSelection getUserInput();
    void setUserInput(ActionSelection s);
    int getNumRecord();
    void setNumRecord(int num);
};

#endif