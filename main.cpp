#include <iostream>
#include <vector>
#include "sqlite/sqlite3.h"
#include "employee/phone.h"
#include "employee/name.h"
#include "employee/employee.h"
#include "menu.h"
#include "trim.h"
#include "helper.h"

using namespace std;

void connect_database(sqlite3 **db)
{
    // Open or create database
    int rc = sqlite3_open("bin\\data.db", db);

    if (rc != SQLITE_OK)
    {
        // fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(*db));
        cerr << "Can't open database: " << sqlite3_errmsg(*db) << endl;
    }
    else
    {
        // fprintf(stdout, "Opened database successfully\n");
        cout << "Opened database successfully" << endl;
    }
}

void create_table(sqlite3 **db)
{
    char *zErrMsg = 0;
    
    /* Execute SQL statement */
    int rc = sqlite3_exec(*db, SQL_CREATE_TABLE_0.c_str(), Helper::sql_callback, 0, &zErrMsg);
    if (rc != SQLITE_OK)
    {
        // fprintf(stderr, "SQL error: %s\n", zErrMsg);
        cerr << "SQL error: " << zErrMsg << endl;
        sqlite3_free(zErrMsg);
    }
    else
    {
        // fprintf(stdout, "Table created successfully\n");
        cout << "Table created successfully" << endl;
    }
}

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
    connect_database(&db);
    create_table(&db);
    while (1)
    {
        Menu *menu = new Menu(&db);
    }
    sqlite3_close(db);
    return 0;
}
