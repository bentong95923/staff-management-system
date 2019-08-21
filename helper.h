#ifndef HELPER_H_
#define HELPER_H_

#include <iostream>
#include <vector>
#include <any>

using namespace std;

class Helper
{
public:
    static bool is_element_in_vector(vector<int> v, int e);
    static bool is_element_in_vector(vector<char> v, char e);
    static bool is_element_in_vector(vector<string> v, string e);

    static string vector_to_string(vector<int> v, string delimiter);
    static string vector_to_string(vector<char> v, string delimiter);
    static string vector_to_string(vector<string> v, string delimiter);

    static int sql_callback(void *NotUsed, int argc, char **argv, char **azColName);
};

#endif