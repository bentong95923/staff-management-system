#include "sqlite3source.h"
#include "system/management.h"
#include "misc/sql.h"

int main()
{
    // Create database pointer for SQLite
    sqlite3 *db;
    /*
        Functionality:
        View an employee
        Edit an employee
        Delete an employee
        Create an employee
     */

    System *system = new System(&db);
    system->run();
    
    return 0;
}
