#ifndef CONFG_H_
#define CONFG_H_

/* 
 * confg.h is the header file which defines and stores the all the settings for this app.
 * It aims to not affect any part of the program when the structure of tables are required to be changed / added.
 * This header file can be edited for altering table structure to fit the organization purpose.
 */

// Put the organization name below.
#define ORGANIZATION_NAME "Love C++ Limited"

#include <vector>
#include <string>

using namespace std;

// Path and name of the database file
const string DBPath = "bin/data.db";
const string TABLE_NAME = "Staff_Details";
// Table fields -- make sure to content Email, First Name and DOB
const vector<string> ALL_FIELDS_TABLE = {"First_Name", "Middle_Name", "Last_Name", "DOB", "Title", "Department", "Landline", "Mobile", "Email", "Salary"};

/* ---------------------------- View action configuration---------------------------- */
// Specified field used for View action: Email, First Name, DOB and ID (intrinsically created)
// These four fields are compulsory and cannot be removed for view action.
const string EMAIL_FIELD = ALL_FIELDS_TABLE.at(8);
const string FIRST_NAME_FIELD = ALL_FIELDS_TABLE.at(0);
const string DOB_FIELD = ALL_FIELDS_TABLE.at(3);

/* ---------------------------- Create action configuration ---------------------------- */
const vector<int> OPTIONAL_FIELDS_TABLE = {1, 3, 6, 8}; // Position for the field that is optional
// Data type for each field in the table. "not null" = compulsory field
const vector<string> DATA_TYPE_N_KEYWORDS = {"text not null", "text", "text not null", "date", "text not null", "text not null", "text", "text", "text not null", "real"};

#endif