#include "helper.h"

bool Helper::is_element_in_vector(vector<int> v, int e)
{
    for (auto x : v)
    {
        if (x == e)
        {
            return true;
        }
    }
    return false;
}

bool Helper::is_element_in_vector(vector<char> v, char e)
{
    for (auto x : v)
    {
        if (x == e)
        {
            return true;
        }
    }
    return false;
}

bool Helper::is_element_in_vector(vector<string> v, string e)
{
    for (auto x : v)
    {
        if (x == e)
        {
            return true;
        }
    }
    return false;
}

string Helper::vector_to_string(vector<int> v, string delimiter)
{
    string vector_str = "";
    for (int i = 0; i < v.size(); i++)
    {
        i != v.size() - 1 ? vector_str += ("'" + to_string(v.at(i)) + "'" + delimiter) : (vector_str += "'" + to_string(v.at(i)) + "'");
    }
    return vector_str;
}

string Helper::vector_to_string(vector<char> v, string delimiter)
{
    string vector_str = "";
    for (int i = 0; i < v.size(); i++)
    {
        i != v.size() - 1 ? vector_str += ("'" + to_string(v.at(i)) + "'" + delimiter) : (vector_str += "'" + to_string(v.at(i)) + "'");
    }
    return vector_str;
}

string Helper::vector_to_string(vector<string> v, string delimiter)
{
    string vector_str = "";
    for (int i = 0; i < v.size(); i++)
    {
        i != v.size() - 1 ? vector_str += ("'" + v.at(i) + "'" + delimiter) : (vector_str += "'" + v.at(i) + "'");
    }
    return vector_str;
}

int Helper::sql_callback(void *NotUsed, int argc, char **argv, char **azColName)
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