#ifndef EDIT_H_
#define EDIT_H_

#include "action.h"

class Edit : public Action
{
public:
    Edit();
    ~Edit();
    void view();
    bool askUserInput();
    bool execute(sqlite3 **db);
    bool edit(sqlite3 **db);
};

#endif