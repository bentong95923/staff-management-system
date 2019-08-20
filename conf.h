#ifndef CONF_H_
#define CONF_H_

// Define configuration variables for this app
#include <vector>
using namespace std;

// Create class
#define MAX_CREATE_INPUTS 9
#define ORGANIZATION_NAME "Panda Limited"
const vector<int> OPTIONAL_FIELD_CREATE = {1, 3, 6, 8}; // Position for the field that is optional
const vector<string> ALL_FIELD_CREATE = {"First Name", "Middle Name", "Last Name", "Date of Birth", "Title", "Department", "Landline", "Email", "Salary"};
const vector<string> TABLE_NAME = {"STAFF_DETAIL"};

#endif