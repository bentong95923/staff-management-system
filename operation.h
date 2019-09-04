#ifndef OPERATION_H_
#define OPERATION_H_

#include <iostream>
#include <sstream>
#include <vector>
#include "sqlite/sqlite3.h"
#include "sql.h"

#include "vectorext.h"
#include "trim.h"
#include "validator.h"

using namespace std;

class Operation
{
private:
    vector<string> userInput;
public:
    virtual void view() = 0;
    virtual bool askUserInput() = 0;
    virtual bool execute(sqlite3 **db) = 0;
    vector<string> getUserInput();
    void setUserInput(vector<string> i);
};

#endif