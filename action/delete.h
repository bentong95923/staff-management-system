#ifndef DELETE_H_
#define DELETE_H_

#include "action.h"

class Delete : public Action
{
public:
    Delete();
    ~Delete();
    void view();
    bool askUserInput();
    bool execute(sqlite3 **db);
};

#endif