#include "view.h"

View::View()
{
    // Initialize user input vector
    vector<string> v(AVAILABLE_SEARCH_FIELD_TABLE_0.size() + 1, "");
    this->setUserInput(v);
}

void View::view()
{
    cout << "Please provide at least one of the following information to look up a staff member's profile:" << endl;
    cout << "1. ID " << endl;
    int i = 1;
    for (int j = 0; j < ALL_FIELDS_TABLE_0.size(); j++)
    {
        if (VectorExtension::is_element_in_vector(AVAILABLE_SEARCH_FIELD_TABLE_0, j))
        {
            cout << i << ". " << ALL_FIELDS_TABLE_0.at(j) << endl;
            i++;
        }
    }
}

bool View::askUserInput()
{
    return false;
}

bool View::execute(sqlite3 **db)
{
    return false;
}

View::~View()
{
}