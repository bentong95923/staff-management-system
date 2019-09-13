#include "management.h"

System::System(sqlite3 **db)
{
    this->db = db;
    this->numRecord = 0;
    this->userInput = INVALID;
}

void System::run()
{
    SQL::connect_database(this->db);
    while (true)
    {
        this->setUserInput(INVALID);
        this->retrieveDatabaseRecords();
        this->view();
        if (this->askUserInput())
        {
            while (true)
            {
                if (!this->execute())
                {
                    break;
                }
            }
        }
        else
        {
            break;
        }
    }
    SQL::disconnect_database(this->db);
}

void System::view()
{
    cout << endl;
    cout << "Welcome to " << ORGANIZATION_NAME << "'s Staff Management System!" << endl;
    cout << "---------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "Please enter the number which corresponding to the following operation:" << endl;
    cout << "1 - View staff member's profiles" << (this->getNumRecord() == 0 ? " (DISABLED) " : "") << endl;
    cout << "2 - Edit staff member's profiles" << (this->getNumRecord() == 0 ? " (DISABLED) " : "") << endl;
    cout << "3 - Create staff member's profiles" << endl;
    cout << "4 - Delete staff member's profiles" << (this->getNumRecord() == 0 ? " (DISABLED) " : "") << endl;
    string tmp = "";
    tmp = this->getNumRecord() == 0 ? "There are no profiles found in the database" : this->getNumRecord() == 1 ? "There is 1 profile found in the database" : "There are " + to_string(this->getNumRecord()) + " profiles in the database";
    cout << endl;
    cout << "     ---   " << tmp << "   ---     " << endl;
    cout << endl;
    cout << "To quit the system, type 'quit'." << endl;
    cout << endl;
}

void System::retrieveDatabaseRecords()
{
    string sql = "select count(*) from " + TABLE_NAME;
    char *zErrMsg = 0;
    int countSql = 0;
    /* Execute SQL statement */
    int rc = sqlite3_exec(*db, sql.c_str(), SQL::sql_callback_retrieve_db_records, &countSql, &zErrMsg);
    if (rc != SQLITE_OK)
    {
        cerr << "SQL error in " << __func__ << ": " << zErrMsg << endl;
        sqlite3_free(zErrMsg);
    }
    else
    {
        this->setNumRecord(countSql);
    }
}

bool System::askUserInput()
{
    char s[256];
    bool validInput = false;
    cin.clear();
    while (!validInput)
    {
        cout << "> ";
        cin.getline(s, 256);
        string sss(s);

        // Trim whitespace
        sss = trim(sss);
        istringstream parse(sss);
        if (sss == "quit")
        {
            return false;
            break;
        }
        else if (Validator::validate_positive_integer(sss))
        {
            if (stoi(sss) >= (int)VIEW && stoi(sss) <= (int)DELETE)
            {
                if ((this->getNumRecord() == 0) && stoi(sss) != (int)CREATE)
                {
                    cout << "You cannot view, edit or delete any profiles as there are no profiles found in the database. Please try again." << endl;
                    return true;
                }
                else
                {
                    this->setUserInput((ActionSelection)stoi(sss));
                    validInput = true;
                }
            }
            else
            {
                cout << "Please enter a number corresponding to the actions." << endl;
            }
        }
        else
        {
            cout << "Invalid input. Please try again." << endl;
        }
    }
    return validInput;
}

bool System::execute()
{
    switch (this->getUserInput())
    {
    case VIEW:
    {
        View *op = new View();
        op->view();
        if (!op->askUserInput())
        {
            return false;
        }
        else
        {
            return op->execute(this->db);
        }
        break;
    }
    case EDIT:
    {
        Edit *op = new Edit();
        op->view();
        if (!op->askUserInput())
        {
            return false;
        }
        else
        {
            return op->execute(this->db);
        }
        break;
    }
    case CREATE:
    {
        Create *op = new Create();
        op->view();
        if (!op->askUserInput())
        {
            return false;
        }
        else
        {
            return op->execute(this->db);
        }
        break;
    }
    case DELETE:
    {
        Delete *op = new Delete();
        op->view();
        if (!op->askUserInput())
        {
            return false;
        }
        else
        {
            return op->execute(this->db);
        }
        break;
    }

    default:
    {
        return false;
        break;
    }
    }
}

ActionSelection System::getUserInput()
{
    return this->userInput;
}

void System::setUserInput(ActionSelection s)
{
    this->userInput = s;
}

int System::getNumRecord()
{
    return this->numRecord;
}

void System::setNumRecord(int num)
{
    this->numRecord = num;
}

System::~System()
{
}