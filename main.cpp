#include <iostream>
#include <vector>
#include "sqlite/sqlite3.h"
#include "employee/phone.h"
#include "employee/name.h"
#include "employee/employee.h"
#include "menu.h"
#include "trim.h"

using namespace std;

static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    int i;
    for (i = 0; i < argc; i++)
    {
        cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << endl;
        // printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    cout << endl;
    return 0;
}

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

void create_table(sqlite3 **db, string table_name)
{
    char *zErrMsg = 0;
    string sql = "CREATE TABLE "+table_name+"(\
        ID INT PRIMARY KEY NOT NULL,\
        FNAME TEXT NOT NULL,\
        MNAME TEXT,\
        LNAME TEXT NOT NULL,\
        DOB DATE,\
        TITLE TEXT NOT NULL,\
        DEPARTMENT TEXT NOT NULL,\
        LANDLINE TEXT,\
        EMAIL TEXT NOT NULL,\
        SALARY REAL\
        );";
    /* Execute SQL statement */
    int rc = sqlite3_exec(*db, sql.c_str(), callback, 0, &zErrMsg);
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
    create_table(&db, TABLE_NAME.at(0));
    /* for(int i = 0; i < 9; i++) {
        cout << (find(OPTIONAL_FIELD_CREATE.begin(), OPTIONAL_FIELD_CREATE.end(), i) != OPTIONAL_FIELD_CREATE.end());
    } */
    while (1)
    {
        Menu *menu = new Menu(&db);
    }
    sqlite3_close(db);
    return 0;
}
