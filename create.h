#ifndef CREATE_H_
#define CREATE_H_

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>
#include "sqlite/sqlite3.h"
#include "trim.h"
#include "conf.h"
#include "vectorext.h"
#include "sql.h"

using namespace std;

class Create
{
private:
    vector<string> userInput;
public:
    Create();
    ~Create();
    void view();
    void askUserInput();
    void execute(sqlite3 **db);
    vector<string> getUserInput();
    void setUserInput(vector<string> i);
};

#endif