#include <iostream>
#include <vector>
#include "employee/phone.h"
#include "employee/name.h"
#include "employee/employee.h"
#include <sqlite3.h>

using namespace std;

static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    int i;
    for (i = 0; i < argc; i++)
    {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

void connect_database(sqlite3 **db)
{
    // Open or create database
    int rc = sqlite3_open("bin\\data.db", db);

    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(*db));
    }
    else
    {
        fprintf(stdout, "Opened database successfully\n");
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
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else
    {
        fprintf(stdout, "Table created successfully\n");
    }
}

int main()
{
    // Create database pointer for SQLite
    sqlite3 *db;

    connect_database(&db);
    create_table(&db);
    sqlite3_close(db);
    return 0;
}
