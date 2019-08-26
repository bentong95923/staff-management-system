#include "sqlite/sqlite3.h"
#include "menu.h"
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
    while (1)
    {
        Menu *menu = new Menu(&db);
    }
    sqlite3_close(db);
    return 0;
}
