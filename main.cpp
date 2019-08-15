#include <iostream>
#include <vector>
#include "phone.h"
#include "name.h"
#include "employee.h"
#include "sqlite3.h"

using namespace std;

int main()
{
    sqlite3 **ppDB;
    sqlite3_open("data.db",ppDB);
}