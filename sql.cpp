#include "sql.h"

void SQL::connect_database(sqlite3 **db)
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

void SQL::create_table(sqlite3 **db)
{
    char *zErrMsg = 0;
    
    /* Execute SQL statement */
    int rc = sqlite3_exec(*db, SQL_CREATE_TABLE_0.c_str(), SQL::sql_callback, 0, &zErrMsg);
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

int SQL::sql_callback(void *NotUsed, int argc, char **argv, char **azColName)
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