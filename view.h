#ifndef VIEW_H_
#define VIEW_H_

#include "operation.h"

class View : public Operation
{
public:
    View();
    ~View();
    void view();
    bool askUserInput();
    bool execute(sqlite3 **db);
};

#endif