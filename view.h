#ifndef CREATE_H_
#define CREATE_H_

#include "operation.h"

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