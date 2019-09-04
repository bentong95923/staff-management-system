#ifndef OPERATION_H_
#define OPERATION_H_

#include <sstream>
#include <vector>
#include <string>
#include "sqlite/sqlite3.h"
#include "sql.h"

#include "vectorext.h"
#include "trim.h"
#include "validator.h"

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