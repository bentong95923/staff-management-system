#ifndef CREATE_H_
#define CREATE_H_

#include "action.h"

class Create : public Action
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