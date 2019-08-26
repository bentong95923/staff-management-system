#include "sqlite/sqlite3.h"
#include "management.h"
#include "sql.h"
#include "validator.h"

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

    bool statusOn = true;
    while (statusOn)
    {
        System *system = new System(&db);
        statusOn = system->run();
    }
    SQL::disconnect_database(&db);
    return 0;
}
