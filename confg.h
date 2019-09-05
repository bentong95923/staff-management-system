#ifndef CONFG_H_
#define CONFG_H_

#define ORGANIZATION_NAME "Panda Limited"

/* 
 * confg.h is the header file which defines and stores the all the settings for this app.
 * It aims to not affect any part of the program when the structure of tables are required to be changed / added.
 * This header file can be edited for altering table structure to fit the organization purpose.
 */
#include <vector>
#include <string>

using namespace std;

// class AppConfig
//{
// private:
    const vector<string> TABLE_NAME = {"Staff_Details"}; // {Table 0, Table 1, Table 2, ......}
    // "Staff_Details" table
    const vector<string> ALL_FIELDS_TABLE_0 = {"First_Name", "Middle_Name", "Last_Name", "DOB", "Title", "Department", "Landline", "Mobile", "Email", "Salary"};
    /* ---------------------------- Create action ---------------------------- */
    // #define MAX_CREATE_INPUTS 9
    const vector<int> OPTIONAL_FIELDS_TABLE_0 = {1, 3, 6, 8}; // Position for the field that is optional
    const vector<string> DATA_TYPE_N_KEYWORDS = {"text not null", "text", "text not null", "date", "text not null", "text not null", "text", "text not null", "real"};
    const string SQL_CREATE_TABLE_0 = "create table " + TABLE_NAME.at(0) + "(\
                ID integer primary key autoincrement," +
                                      ALL_FIELDS_TABLE_0.at(0) + " text not null," 
                                      + ALL_FIELDS_TABLE_0.at(1) + " text,"
                                      + ALL_FIELDS_TABLE_0.at(2) + " text not null," 
                                      + ALL_FIELDS_TABLE_0.at(3) + " date," 
                                      + ALL_FIELDS_TABLE_0.at(4) + " text not null," 
                                      + ALL_FIELDS_TABLE_0.at(5) + " text not null," 
                                      + ALL_FIELDS_TABLE_0.at(6) + " text," 
                                      + ALL_FIELDS_TABLE_0.at(7) + " text," 
                                      + ALL_FIELDS_TABLE_0.at(8) + " text not null," 
                                      + ALL_FIELDS_TABLE_0.at(9) + " real\
                );";
    const vector<int>AVAILABLE_SEARCH_FIELD_TABLE_0 = {0, 3, 8};// Position for the field that is available for look up in view operation

// public:
// };

#endif