#ifndef ACTION_H_
#define ACTION_H_

#include <iostream>
#include <sstream>
#include <vector>
#include "../sqlite/sqlite3.h"
#include "../misc/sql.h"

#include "../misc/vectorext.h"
#include "../misc/trim.h"
#include "../misc/validator.h"

using namespace std;

class Action
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