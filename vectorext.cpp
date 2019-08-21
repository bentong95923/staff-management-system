#include "vectorext.h"

bool VectorExtension::is_element_in_vector(vector<int> v, int e)
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

bool VectorExtension::is_element_in_vector(vector<char> v, char e)
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

bool VectorExtension::is_element_in_vector(vector<string> v, string e)
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

string VectorExtension::vector_to_string(vector<int> v, string delimiter)
{
    string vector_str = "";
    for (int i = 0; i < v.size(); i++)
    {
        i != v.size() - 1 ? vector_str += ("'" + to_string(v.at(i)) + "'" + delimiter) : (vector_str += "'" + to_string(v.at(i)) + "'");
    }
    return vector_str;
}

string VectorExtension::vector_to_string(vector<char> v, string delimiter)
{
    string vector_str = "";
    for (int i = 0; i < v.size(); i++)
    {
        i != v.size() - 1 ? vector_str += ("'" + to_string(v.at(i)) + "'" + delimiter) : (vector_str += "'" + to_string(v.at(i)) + "'");
    }
    return vector_str;
}

string VectorExtension::vector_to_string(vector<string> v, string delimiter)
{
    string vector_str = "";
    for (int i = 0; i < v.size(); i++)
    {
        i != v.size() - 1 ? vector_str += ("'" + v.at(i) + "'" + delimiter) : (vector_str += "'" + v.at(i) + "'");
    }
    return vector_str;
}
