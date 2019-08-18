#include <iostream>
#include <vector>
#include <sqlite3.h>
#include "employee/phone.h"
#include "employee/name.h"
#include "employee/employee.h"

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

void create_table(sqlite3 **db)
{
    char *zErrMsg = 0;
    char *sql = "CREATE TABLE STAFF_DETAIL(\
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
    int rc = sqlite3_exec(*db, sql, callback, 0, &zErrMsg);
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

void display_menu()
{
    cout << "Welcome to XXXXXXX's Staff Management System!" << endl;
    cout << endl;
    cout << "Please select the following actions by entering the corresponding number, then hit 'Enter'." << endl;
    cout << "1. View a staff member's profile" << endl;
    cout << "2. Edit a staff member's profile" << endl;
    cout << "3. Create a staff member's profile" << endl;
    cout << "4. Delete a staff member's profile" << endl;
}

void get_user_input_n_run()
{
    int selection = 0;
    cin >> selection;
    switch (selection)
    {
    case 1:
        /* code */
        break;
    case 2:
        /* code */
        break;
    case 3:
        /* code */
        break;
    case 4:
        /* code */
        break;

    default:
        break;
    }
}

void add_staff()
{
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
    while (1)
    {
        display_menu();
        get_user_input_n_run();
        // create_table(&db); admin
    }
    sqlite3_close(db);

    return 0;
}
