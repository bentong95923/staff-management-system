#ifndef CREATE_H_
#define CREATE_H_

// #include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>
#include "sqlite/sqlite3.h"
#include "trim.h"
#include "configuration.h"
#include "vectorext.h"
#include "operation.h"
#include "sql.h"
#include "validator.h"

// using namespace std;

class Create : public Operation
{
public:
    Create();
    ~Create();
    void view();
    bool askUserInput();
    bool execute(sqlite3 **db);
    static bool validateInput(string input, int i);
};

#endif