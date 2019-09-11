# Staff Management System
by Benjamin Tong

This is an CMD application run with SQLite to for a staff management system in an organization. Visual Studio Code is used as the editor and builder of the application. Database will be created to store staff details.


### Documentation
##### Specification

Language: C++, SQL (SQLite)

IDE: Visual Studio Code

Environment: Windows 7 or above, Windows Server 2008 or above
This application has not been tested under Linux environment but it may work with slight or no amendment on the building process.

##### Build the application
1. Download Visual Studio Code (VS Code) for Windows on https://code.visualstudio.com/, and install it.
2. Open VS Code once installed, and click "File" -> "Open Folder...", then open the directory with "main.cpp".
3. Press Ctrl + Alt + B to build and run the appliaction.
<br />

##### Initialization:
If the database (.db file) is not present then the application will automatically create a new emply database. The application will ask the user to create a staff member's profile if there are no records in the database.
<br />
Create action will only be available if there are no profiles in the database.
<br />

### Functionality:
##### - View (Selection 1)
User can search any profiles by providing ID, First Name, DOB or Email.
<br />

##### - Edit (Selection 1)

User can edit any profiles by providing ID. The profile will be displayed to user before editing.
After entering the editing mode, user can specify the field(s) to be edited for the profile and change the content of the fields.
Once finished editing, the system will give a preview to summarize what information will be changed of the profile, and will write changes to the database.

##### - Create (Selection 1)
User can create a new profile by filing information. * mean compulsory field to be filled.
After user enter the information, database will automatically create the ID of the newly created profile.

##### - Delete (Selection 1)
User can delete any profiles by providing ID. The profile will be displayed to user before deleting.
Once user confirmed to delete a particular profile, it will be removed from the database permanently.
