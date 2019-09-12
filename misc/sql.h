#ifndef SQL_H_
#define SQL_H_

#include <iostream>
#include "../sqlite3source.h"
#include "../confg.h"

using namespace std;

class SQL
{
public:
    static void connect_database(sqlite3 **db);
    static void create_table(sqlite3 **db);
    static void disconnect_database(sqlite3 **db, bool displayMsg = true);
    static int sql_callback(void *NotUsed, int argc, char **argv, char **azColName);
    static int sql_callback_init_check(void *NotUsed, int argc, char **argv, char **azColName);
    static int get_n_CallBackCalled();
};

#endif