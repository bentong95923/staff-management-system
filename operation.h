#ifndef OPERATION_H_
#define OPERATION_H_

#include <vector>
#include <algorithm>
#include <string>
#include "sqlite/sqlite3.h"
#include "sql.h"

class Operation
{
private:
    vector<string> userInput;
public:
    // Operation();
    // ~Operation();
    virtual void view() = 0;
    virtual bool askUserInput() = 0;
    virtual bool execute(sqlite3 **db) = 0;
    vector<string> getUserInput();
    void setUserInput(vector<string> i);
};

#endif