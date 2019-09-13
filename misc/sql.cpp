#include "sql.h"

void SQL::connect_database(sqlite3 **db)
{
    int rcR = sqlite3_open_v2(DBPath.c_str(), db, SQLITE_OPEN_READONLY, 0);

    SQL::disconnect_database(db, false);

    if (rcR != SQLITE_OK)
    {
        cout << "Database not detected!" << endl;
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
    string sql_create_table = "create table " + TABLE_NAME + "(ID integer primary key autoincrement,";

    for (int i = 0; i < ALL_FIELDS_TABLE.size(); i++)
    {
        string cm = ",";
        if (i == ALL_FIELDS_TABLE.size() - 1)
        {
            cm = "";
        }
        sql_create_table += ALL_FIELDS_TABLE.at(i) + " " + DATA_TYPE_N_KEYWORDS.at(i) + cm;
    }
    sql_create_table += ");";

    char *zErrMsg = 0;

    /* Execute SQL statement */
    int rc = sqlite3_exec(*db, sql_create_table.c_str(), SQL::sql_callback, 0, &zErrMsg);
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
int SQL::sql_callback_retrieve_db_records(void *trackResult, int argc, char **argv, char **azColName)
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
