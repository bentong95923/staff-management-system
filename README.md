# Staff Management System
###### by Benjamin Tong

This is an CMD application run with SQLite to for a staff management system in an organization. Visual Studio Code is used as the editor and builder of the application. Database will be created to store staff details.

This is one of my self project in which I aim to use different tech and create useful app.

# Documentation
### Specification

Language: C++, SQL (SQLite), C (only used for building source file for SQLite)

IDE used: Visual Studio Code

Compiler: gcc - building SQLite source file, g++ - building the app

Support Environment: <br />
Windows 7 or above, Windows Server 2008 or above <br />
Linux (It was only tested in Ubuntu but should be fine in any Linux environment)

### Pre-installation
It is required to install the gcc and g++ compiler in order to build the application. <br />
Suggested source for compiler: <br />
Windows - Cygwin (http://www.cygwin.com/) <br />
Linux - by the command as follow: <br />
```
$ sudo apt install g++
```
or
```
$ sudo apt install build-essential
```

### Build the application (Windows)
#### with Visual Studio Code
1. Download Visual Studio Code (VS Code) for Windows on https://code.visualstudio.com/, and install it.
2. Clone this repo via git or click "Clone or download".
3. Open VS Code once installed, and click "File" -> "Open Folder...", then open the directory with "main.cpp".
4. Press Ctrl + Alt + B. VS Code will automatically run the commands to build and run the appliaction.

#### without Visual Studio Code
1. Clone this repo via git or click "Clone or download".
2. Open Command Prompt or PowerShell, and run the following command lines:

##### a) Build the SQLite source file
```
gcc -c sqlite/sqlite3.c -o bin/sqlite3.o
```
##### b) Build the application with the source file
```
g++ misc/*.cpp system/*.cpp action/*.cpp *.cpp bin/sqlite3.o -o bin/staff
```
##### c) Run the application (Make sure it is a <b>forward</b> slash not a <b>back</b> slash)
```
bin\staff
```

### Build the application (Linux)
1. Install SQLite3
```
$ sudo apt-get install sqlite3 libsqlite3-dev 
```
2. Build the application with SQLite package which was just installed
```
$ g++ misc/*.cpp system/*.cpp action/*.cpp *.cpp -o bin/staff -lsqlite3
```
3. Run the application (Make sure it is a <b>back</b> slash not a <b>forward</b> slash)
```
$ bin/staff
```

### Initialization
If the database (.db file) is not present then the application will automatically create a new emply database. The application will ask the user to create a staff member's profile if there are no records in the database.
<br />
Create action will only be available if there are no profiles in the database.
<br />

# Functionality
### View (Selection 1)
User can search to view any profiles by providing ID, First Name, DOB or Email.

### Edit (Selection 2)

User can edit any profiles by providing ID. The profile will be displayed to user before editing.
After entering the editing mode, user can specify the field(s) to be edited for the profile and change the content of the fields.
Once finished editing, the system will give a preview to summarize what information will be changed of the profile, and will write changes to the database.

### Create (Selection 3)
User can create a new profile by filing information. * mean compulsory field to be filled.
After user entered the information, database will automatically create the ID of the newly created profile.

### Delete (Selection 4)
User can delete any profiles by providing ID. The profile will be displayed to user before deleting.
Once user confirmed to delete a particular profile, it will be removed from the database permanently.
