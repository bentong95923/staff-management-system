#ifndef VIEW_H_
#define VIEW_H_

#include "action.h"

class View : public Action
{
public:
    View();
    ~View();
    void view();
    bool askUserInput();
    bool execute(sqlite3 **db);
};

#endif