#include "sqlite/sqlite3.h"
#include "management.h"
#include "sql.h"

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
        List all staff member?? (what happen if got so many?)
     */
    SQL::connect_database(&db);
    SQL::create_table(&db);

    System *system = new System(&db);
    system->run();
    
    SQL::disconnect_database(&db);
    return 0;
}
