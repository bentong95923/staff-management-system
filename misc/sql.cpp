#include "sql.h"

void SQL::connect_database(sqlite3 **db)
{
    int rcR = sqlite3_open_v2(DBPath.c_str(), db, SQLITE_OPEN_READONLY, 0);

    SQL::disconnect_database(db, false);

    if (rcR != SQLITE_OK)
    {
        cout << "Creating database..............................";
    }
    else
    {
        cout << "Connecting database..............................";
    }
    // Open or create database
    int rcO = sqlite3_open(DBPath.c_str(), db);

    if (rcO != SQLITE_OK)
    {
        cerr << "failed! " << endl;
        cerr << "SQL Error: " << sqlite3_errmsg(*db) << endl;
    }
    else
    {
        cout << "success!" << endl;
        if (rcR != SQLITE_OK)
        {
            cout << "Initializing database..............................";
            SQL::create_table(db);
        }
    }
}

void SQL::create_table(sqlite3 **db)
{
    char *zErrMsg = 0;

    /* Execute SQL statement */
    int rc = sqlite3_exec(*db, SQL_CREATE_TABLE_0.c_str(), SQL::sql_callback, 0, &zErrMsg);
    if (rc != SQLITE_OK)
    {
        cerr << "failed!" << endl;
        cerr << "SQL error in " << __func__ << ": " << zErrMsg << endl;
        sqlite3_free(zErrMsg);
    }
    else
    {
        cout << "success!" << endl;
    }
}

void SQL::disconnect_database(sqlite3 **db, bool displayMsg)
{
    char *zErrMsg = 0;
    int rc = sqlite3_close(*db);
    if (rc != SQLITE_OK)
    {
        cerr << "Error occurs when closing!" << endl;
        cerr << "SQL error in " << __func__ << ": " << zErrMsg << endl;
        sqlite3_free(zErrMsg);
    }
    else
    {
        if (displayMsg)
        {
            cout << "Database connection closed. Bye!" << endl;
        }
    }
}

// SQL callback function for printing records according to SQL enquiry
int SQL::sql_callback_init_check(void *trackResult, int argc, char **argv, char **azColName)
{
    int *count = (int *)trackResult;
    *count = stoi(argv[0]);
    return 0;
}

// SQL callback function for printing records according to SQL enquiry
int SQL::sql_callback(void *trackResult, int argc, char **argv, char **azColName)
{
    int *flag = (int *)trackResult;
    (*flag)++;
    if (*flag == 1)
    {
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < argc; i++)
    {
        cout << azColName[i] << ": " << (argv[i] ? argv[i] : "NULL") << endl;
    }

    return 0;
}
