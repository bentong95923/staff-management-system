#include <iostream>
#include <vector>
#include "phone.h"
#include "name.h"
#include "employee.h"
#include "sqlite3.h"

using namespace std;

int main()
{
    sqlite3 *db;
    int rc = sqlite3_open("data.db", &db);

    if (rc)
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return (0);
    }
    else
    {
        fprintf(stderr, "Opened database successfully\n");
    }
    sqlite3_close(db);
}