#include <iostream>
#include <iomanip>
#include <string>
#include <conio.h>
#include <mysql.h> //libmysql
#include <chrono>
#include <sstream>
#include <regex> 


using namespace std;


void StudentRegistration();
void LoginAdmin();
void LoginStudent();
void AdminMenu();
void StudentMenu();
void RoomItem();
void RoomItemReport();
void DeleteRoomItemReport();
void DisplayRoomItemReport();
void UpdateRoomItemReport();
void StudentReportQuery();
void UpdateStudent();
void ElectricalAppliance();
void UpdateRoomItem();
void SendReport(); 
void StudentRegistration();
void AddRoomItem();
void DisplayRoomItem();
void DeleteRoomItem();
void CalculateAppliance();
void StudentBlock();
void StudentFaculty();
void StudentLevel();
void StudentRoom();
void TotalReport();
void CancelAppRegistration();
void ApplianceRegistrationReceipt();
void AdminAppRegReceipt();
void RemoveStudent();
void StudentOption();
bool isValid(const string& studentEmail);

string matricNo;
string adminID;
string roomNo;
string currDate;
string reportId;
double totalRate;


int qstate;
MYSQL* conn;
MYSQL_ROW row;
MYSQL_RES* res;

class db_response
{
public:
    static void ConnectionFunction()
    {
        conn = mysql_init(0);
        if (conn)
            cout << "Database Connected" << endl;
        else
            cout << "Failed To Connect!" << endl;

        conn = mysql_real_connect(conn, "localhost", "root", "", "workshop1", 3306, NULL, 0);
        if (conn)
            cout << "Database Connected To MySql" << endl;
        else
            cout << "Failed To Connect!" << endl;
    }
};
int main() {
    system("cls");
    system("title My Project");
    db_response::ConnectionFunction();

    char user;

    cout <<endl;
    
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "-------------------------------------------------------------     WELCOME TO STUDENT HOSTEL MANAGEMENT SYSTEM     ----------------------------------------------------------------" << endl;
    cout << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << endl;
    cout << setw(105) << ">>>>>>>   CHOOSE USER     <<<<<<<" << endl;
    cout << endl;
    cout <<  setw(90)<< "[1] Admin" << setw(50) << endl;
    cout <<  setw(92)<< "[2] Student"<<setw(50) << endl;
    
    cout << endl;
    cout << setw(106) << "Please choose either [1] or [2] :  ";
    cin >> user;

    while (user != '1' && user != '2')
    {
        cout << setw(115) << "Wrong choice! Please choose either [1] or [2] :  ";
        cin >> user;
    }

    if (user == '1') {
        LoginAdmin();
    }
    
    else if (user == '2') {
        LoginStudent();
    }

    return 0;
}


void LoginAdmin()
{
    system("cls");
    string adminPassword, adminName;
    char ch, k;

    cout << endl;

    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    
    cout << endl;
    cout << "-------------------------------------------------------------     WELCOME TO STUDENT HOSTEL MANAGEMENT SYSTEM     ----------------------------------------------------------------" << endl;
    cout << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << endl;
    cout << setw(95) << "--- Login Page ---" << endl;
    cout << "\n";
    cout << setw(88) << "Admin ID : ";
    cin >> adminID;

    if (adminID.length() != 7)
    {
        cout << "\n";
        cout << "\n";
        cout << setw(115) << "Invalid lenght of Id! Please enter 7 characters for Id" << endl;
        cout << setw(115) << "Press any key to try again...";
        _getch();
        LoginAdmin();

    }

    string checkAdmin_query = "select * from Admin where admin_id = '" + adminID + "'";
    const char* cu = checkAdmin_query.c_str();
    qstate = mysql_query(conn, cu);

    if (!qstate)
    {
        res = mysql_store_result(conn);
        if (res->row_count == 1)
        {
            while (row = mysql_fetch_row(res))
            {
                adminID = row[0];
                
            }

            cout << "\n";
            cout << setw(88) << "Password : ";

            while ((ch = _getch()) != 13)
            {
                adminPassword += ch;
                cout << '*';
            }

            if (adminPassword.length() != 8)
            {
                cout << "\n";
                cout << "\n";
                cout << setw(115) << "Invalid lenght of Password! Please enter 8 characters for password" << endl;
                cout << setw(115) << "Press Any Key to Try Again...";
                _getch();
                LoginAdmin();
            }


            string checkUser_query = "select * from Admin where adminPassword = '" + adminPassword + "' and admin_id = '" + adminID + "'";
            const char* cu = checkUser_query.c_str();
            qstate = mysql_query(conn, cu);

            if (!qstate)
            {
                res = mysql_store_result(conn);
                if (res->row_count == 1)
                {
                    while (row = mysql_fetch_row(res))
                    {

                        adminPassword = row[0];
                    }

                    char a = 177, b = 219;

                    printf("\n\n\n\n");
                    printf("\t\t\t\t\t\t\t\t\t\tVerifying user ...\n\n");
                    printf("\t\t\t\t\t\t\t\t\t\t");

                    // Print initial loading bar
                    for (int i = 0; i < 26; i++)
                        printf("%c", a);

                    // Set the cursor again starting
                    // point of loading bar
                    printf("\r");
                    printf("\t\t\t\t\t\t\t\t\t\t");

                    // Print loading bar progress
                    for (int i = 0; i < 26; i++) {
                        printf("%c", b);

                        // Sleep for 1 second
                        Sleep(100);
                    }
                    AdminMenu();

                }
                else
                {
                    char c;
                    cout << "\n";
                    cout << "\n";
                    cout << setw(115) << "Incorrect password! Want to try again? (Y - yes / N - No): ";
                    cin >> c;

                    while ((c != 'y' && c != 'Y') && (c != 'n' && c != 'N'))
                    {
                        cout << "\n";
                        cout << setw(115) << "Wrong choice! Please choose either Y or N :  ";
                        cin >> c;
                    }


                    if (c == 'y' || c == 'Y')
                        LoginAdmin();
                    else if (c == 'n' || c == 'N')
                        main();
                }
            }
            else
                cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
         
        }
        else
        {
            char c;
            cout << "\n";
            cout << "\n";
            cout << setw(115) << "Incorrect Id! Want to try again? [Y - yes / N - No] : ";
            cin >> c;

            while ((c != 'y' && c != 'Y') && (c != 'n' && c != 'N'))
            {
                cout << "\n";
                cout << setw(115) << "Wrong choice! Please choose either Y or N :  ";
                cin >> c;
            }


            if (c == 'y' || c == 'Y')
                LoginAdmin();
            else if (c == 'n' || c == 'N')
                main();
        }
    }
    else
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;

}

void LoginStudent()
{
    system("cls");
    string studentPassword;

    cout << endl;

    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "-------------------------------------------------------------     WELCOME TO STUDENT HOSTEL MANAGEMENT SYSTEM     ----------------------------------------------------------------" << endl;
    cout << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << endl;
   
    cout << setw(95) << "--- Login Page ---" << endl;
    cout << "\n";
    cout << setw(89) << "Matric No : ";
    cin >> matricNo;

    if (matricNo.length() != 10)
    {
        cout << "\n";
        cout << "\n";
        cout << setw(115) << "Invalid lenght of Matric Number! Please enter 10 characters" << endl;
        cout << setw(115) << "Press any key to try again...";
        _getch();
        LoginStudent();

    }

    string checkStud_query = "select * from student where matricNo = '" + matricNo + "'";
    const char* cu = checkStud_query.c_str();
    qstate = mysql_query(conn, cu);

    if (!qstate)
    {
        res = mysql_store_result(conn);
        if (res->row_count == 1)
        {
            while (row = mysql_fetch_row(res))
            {
                matricNo = row[0];

            }

            cout << "\n";
            cout << setw(89) << "Password : ";

            char ch;
            while ((ch = _getch()) != 13)
            {
                studentPassword += ch;
                cout << '*';
            }

            if (studentPassword.length() != 8)
            {
                cout << "\n";
                cout << "\n";
                cout << setw(115) << "Invalid lenght of Password! Please enter 8 characters for password" << endl;
                cout << setw(115) << "Press any key to try again...";
                _getch();
                LoginStudent();
            }


            string checkUser_query = "select * from student where studentPassword = '" + studentPassword + "' and matricNo  = '" + matricNo + "' ";
            const char* cu = checkUser_query.c_str();
            qstate = mysql_query(conn, cu);

            if (!qstate)
            {
                res = mysql_store_result(conn);
                if (res->row_count == 1)
                {
                    while (row = mysql_fetch_row(res))
                    {

                        studentPassword = row[0];
                    }

                    char a = 177, b = 219;

                    printf("\n\n\n\n");
                    printf("\t\t\t\t\t\t\t\t\t\tVerifying user ...\n\n");
                    printf("\t\t\t\t\t\t\t\t\t\t");

                    // Print initial loading bar
                    for (int i = 0; i < 26; i++)
                        printf("%c", a);

                    // Set the cursor again starting
                    // point of loading bar
                    printf("\r");
                    printf("\t\t\t\t\t\t\t\t\t\t");

                    // Print loading bar progress
                    for (int i = 0; i < 26; i++) {
                        printf("%c", b);

                        // Sleep for 1 second
                        Sleep(100);
                    }
                    StudentMenu();

                }
                else
                {
                    char c;
                    cout << "\n";
                    cout << "\n";
                    cout << setw(115) << "Incorrect password! Want to try again? (Y - yes / N - No): ";
                    cin >> c;

                    while ((c != 'y' && c != 'Y') && (c != 'n' && c != 'N'))
                    {
                        cout << "\n";
                        cout << setw(115) << "Wrong choice! Please choose either Y or N :  ";
                        cin >> c;
                    }


                    if (c == 'y' || c == 'Y')
                        LoginStudent();
                    else if (c == 'n' || c == 'N')
                        main();
                }
            }
            else
                cout << "Query Execution Problem!" << mysql_errno(conn) << endl;

        }
        else
        {
            char c;
            cout << "\n";
            cout << "\n";
            cout << setw(115) << "Incorrect Id! Want to try again? [Y - yes / N - No] : ";
            cin >> c;

            while ((c != 'y' && c != 'Y') && (c != 'n' && c != 'N'))
            {
                cout << "\n";
                cout << setw(115) << "Wrong choice! Please choose either Y or N :  ";
                cin >> c;
            }


            if (c == 'y' || c == 'Y')
                LoginStudent();
            else if (c == 'n' || c == 'N')
                main();
        }
    }
    else
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
}

void AdminMenu()
{
    string adminName;
    int menu;

    string checkAdmin_query = "select adminName from Admin where admin_id = '" + adminID + "'";
    const char* cuAd = checkAdmin_query.c_str();
    qstate = mysql_query(conn, cuAd);
    if (!qstate)
    {
        res = mysql_store_result(conn);
        if (res->row_count == 1)
        {
            while (row = mysql_fetch_row(res))
            {
                adminName = row[0];

            }
        }
    }
    system("cls");
    cout << endl;

    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << setw(80) << "   Hello, " <<adminName<< endl;
    cout << endl;
    cout << "-------------------------------------------------------------     WELCOME TO STUDENT HOSTEL MANAGEMENT SYSTEM     ----------------------------------------------------------------" << endl;
    cout << endl;
    cout << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    // Get the current time in seconds
    time_t t = time(nullptr);

    // Convert the time value to a tm structure
    tm local_time;
    errno_t result = localtime_s(&local_time, &t);


    string currTime = to_string(local_time.tm_year + 1900) + "-" + to_string(local_time.tm_mon + 1) + "-" + to_string(local_time.tm_mday) + " " +
    to_string(local_time.tm_hour) + ":" + to_string(local_time.tm_min);

    cout << setw(90) << "Date and time now is: " << currTime << endl; // print local date and time  

    cout << endl;
    cout << endl;

    cout << setw(95) << "-----Admin Page------" << endl;
    cout << "\n";
    cout <<  setw(90) << "[1] Student Option" << endl << endl;
    cout <<  setw(117)<< "[2] Check Electrical Appliance Registration  " << endl << endl;
    cout <<  setw(85) << "[3] Room Item" << endl << endl;
    cout <<  setw(92) << "[4] Room Item Report" << endl << endl;
    cout <<  setw(96) << "[5] Student Report Query" << endl << endl;
    cout <<  setw(82) << "[6] Logout" << endl << endl;
    cout << "\n";
    cout << setw(90) << "Choose menu: ";
    cin >> menu;

    switch (menu)
    {
    case 1:
        StudentOption(); 
        break;
    case 2:
        AdminAppRegReceipt();
        break;
    case 3:
        RoomItem();
        break;
    case 4:
        RoomItemReport();
        break;
    case 5:
        StudentReportQuery();
        break;
    case 6:
    {
        char a = 177, b = 219;

        printf("\n\n\n\n");
        printf("\t\t\t\t\t\t\t\t\t\tLogging out ...\n\n");
        printf("\t\t\t\t\t\t\t\t\t\t");

        // Print initial loading bar
        for (int i = 0; i < 26; i++)
            printf("%c", a);

        // Set the cursor again starting
        // point of loading bar
        printf("\r");
        printf("\t\t\t\t\t\t\t\t\t\t");

        // Print loading bar progress
        for (int i = 0; i < 26; i++) {
            printf("%c", b);

            // Sleep for 1 second
            Sleep(100);
        }
        main();
    }
        break;
    default:
        cout << "\n";
        cout << setw(90)<<"Please choose between [1 - 6],  Press Any Key To Continue...";
        _getch(); 
        system("cls");
        AdminMenu();
        break;
    }
}

void StudentMenu()
{
    int menu;
    string studentName;

    string checkStudent_query = "select studentName from student where matricNo = '" + matricNo + "'";
    const char* cuAd = checkStudent_query.c_str();
    qstate = mysql_query(conn, cuAd);
    if (!qstate)
    {
        res = mysql_store_result(conn);
        if (res->row_count == 1)
        {
            while (row = mysql_fetch_row(res))
            {
                studentName = row[0];

            }
        }
    }

    system("cls");
    cout << endl;

    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << setw(75) << "   Hello, " << studentName << endl;
    cout << endl;
    cout << "-------------------------------------------------------------     WELCOME TO STUDENT HOSTEL MANAGEMENT SYSTEM     ----------------------------------------------------------------" << endl;
    cout << endl;
    cout << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    // Get the current time in seconds
    time_t t = time(nullptr);

    // Convert the time value to a tm structure
    tm local_time;
    errno_t result = localtime_s(&local_time, &t);


    string currTime = to_string(local_time.tm_year + 1900) + "-" + to_string(local_time.tm_mon + 1) + "-" + to_string(local_time.tm_mday) + " " +
        to_string(local_time.tm_hour) + ":" + to_string(local_time.tm_min);

    cout << setw(90) << "Date and time now is : " << currTime << endl;
    cout << endl;
    cout << endl;

    cout << setw(96) << "-----Student Page------" << endl;
    cout << "\n";
    cout << setw(101) << "[1] Update Student Details" << endl << endl;
    cout << setw(108) << "[2] Register Electrical Appliance" << endl << endl;
    cout << setw(98) << "[3] Update Current Item" << endl << endl;
    cout << setw(95) << "[4] Send Item Report" << endl << endl;
    cout << setw(85)  << "[5] Logout" << endl;
    cout << "\n";
    cout << setw(93) << "Choose menu: ";

    cin >> menu;

    switch (menu)
    {
    case 1:
        UpdateStudent();
        break;
    case 2:
        ElectricalAppliance();
        break;
    case 3:
        UpdateRoomItem();
        break;
    case 4:
        SendReport();
        break;
    case 5:
    {
        char a = 177, b = 219;

        printf("\n\n\n\n");
        printf("\t\t\t\t\t\t\t\t\t\tLogging out ...\n\n");
        printf("\t\t\t\t\t\t\t\t\t\t");

        // Print initial loading bar
        for (int i = 0; i < 26; i++)
            printf("%c", a);

        // Set the cursor again starting
        // point of loading bar
        printf("\r");
        printf("\t\t\t\t\t\t\t\t\t\t");

        // Print loading bar progress
        for (int i = 0; i < 26; i++) {
            printf("%c", b);

            // Sleep for 1 second
            Sleep(100);
        }
     main();
    }
        break;
    default:
        cout << setw(93) << "Please choose between [1 - 5], Press Any key To Continue...";
        _getch();
        system("cls");
        StudentMenu();
        break;
    }
}

void StudentOption ()
{
system("cls");

    char choose;
    int menu;
    cout << endl;

    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "---------------------------------------------------------------      STUDENT HOSTEL MANAGEMENT SYSTEM     ------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    // Get the current time in seconds
    time_t t = time(nullptr);

    // Convert the time value to a tm structure
    tm local_time;
    errno_t result = localtime_s(&local_time, &t);


    string currTime = to_string(local_time.tm_year + 1900) + "-" + to_string(local_time.tm_mon + 1) + "-" + to_string(local_time.tm_mday) + " " +
    to_string(local_time.tm_hour) + ":" + to_string(local_time.tm_min);

    cout << setw(90) << "Date and time now is : " << currTime << endl;
    cout << endl;
    cout << endl;

    cout << setw(95) << "--- Student Option ---" << endl;
    cout << endl;
    cout << setw(96) << "[1] Register Student " << endl << endl;
    cout << setw(93) << "[2] Remove Student" << endl << endl;
    cout << setw(98) << "[3] Back to Admin menu " << endl << endl;

    cout << endl;
    cout << setw(97) << "Please choose between [1-3] : ";

    cin >> menu;

    switch (menu)
    {
    case 1:
        StudentRegistration();
        break;
    case 2:
        RemoveStudent();
        break;
    case 3:
        AdminMenu();
        break;
        /*case 4:
            AdminMenu();
            break;*/
    default:
        cout << setw(97) << "Please choose between 1 - 3. Press Any Key To Continue...";
        _getch();
        system("cls");
        StudentOption();
        break;
    }
}

void StudentRegistration()
{
    system("cls");
    //string matricNo, facultyCode, studentName, studentEmail, studentPhoneNo, semester, dateRegister, roomNo, studentPassword;
    string matricNo, facultyCode, studentName, studentEmail,  studentPhoneNo, semester, dateRegister, roomNo;
    char choose;
    cout << endl;

    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "---------------------------------------------------------------      STUDENT HOSTEL MANAGEMENT SYSTEM     ------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    // Get the current time in seconds
    time_t t = time(nullptr);

    // Convert the time value to a tm structure
    tm local_time;
    errno_t result = localtime_s(&local_time, &t);


    string currTime = to_string(local_time.tm_year + 1900) + "-" + to_string(local_time.tm_mon + 1) + "-" + to_string(local_time.tm_mday) + " " +
        to_string(local_time.tm_hour) + ":" + to_string(local_time.tm_min);

    cout << setw(90) << "Date and time now is : " << currTime << endl;
    cout << endl;
    cout << endl;
    
    cout << setw(99) << "--- Student Registration ---" << endl;
   
    cout << endl;
    cout << setw(103) << "Room Number (Block-Level-Room)  ";
    cout << endl;
    cout << setw(107) << "Block[A/B] , Level[1/2], Room[1-10] ";
    cout << endl;
    cout << endl;
    cout << setw(98) << "Enter Room Number (X-XX-XX) : ";
    cin >> roomNo;

    string checkRoom_query = "select * from student where roomNo = '" + roomNo + "'";
    const char* cu = checkRoom_query.c_str();
    qstate = mysql_query(conn, cu);

    if (!qstate)
    {
        res = mysql_store_result(conn);
        if (res->row_count ==2 )
        {
            cout << endl;
            cout << setw(98) << "Room Number is already occupied. Press Y to Try Again, X to cancel : ";
            cin >> choose;

            while ((choose != 'y' && choose != 'Y') && (choose != 'x' && choose != 'X'))
            {
                cout << endl;
                cout << setw(98) << "Wrong choice! Please choose either Y or X :  ";
                cin >> choose;
            }

                if (choose == 'y' || choose == 'Y')
                    StudentRegistration();

                else if (choose == 'x' || choose == 'X')
                    AdminMenu();
            
        }
        else
        {
            string checkRoom_query = "select * from room where roomNo = '" + roomNo + "'";
            const char* cu = checkRoom_query.c_str();
            qstate = mysql_query(conn, cu);
            if (!qstate)
            {
                res = mysql_store_result(conn);
                if (res->row_count == 1)
                {
                    cout << endl;
                    cout << setw(90) << "Enter Matric Number : ";
                    cin >> matricNo;
                    cout << endl;

                    while (matricNo.length() != 10)
                    {
                        cout << "\n";
                        cout << "\n";
                        cout << setw(115) << "Invalid lenght of Matric Number! Please enter 10 characters of Matric No  : ";
                        cin >> matricNo;

                    }

                    string checkMatricNum_query = "select * from student where matricNo = '" + matricNo + "'";
                    const char* M = checkMatricNum_query.c_str();
                    qstate = mysql_query(conn, M);
                    if (!qstate)
                    {
                        res = mysql_store_result(conn);
                        if (res->row_count == 1)
                        {
                            cout << endl;
                            cout << setw(113) << "Matric number is already registered. Press Y to Try Again, X to cancel  : ";
                            cin >> choose;

                            while ((choose != 'y' && choose != 'Y') && (choose != 'x' && choose != 'X'))
                            {
                                cout << endl;
                                cout << setw(98) << "Wrong choice! Please choose either Y or X :  ";
                                cin >> choose;
                            }
                            if (choose == 'y' || choose == 'Y')
                                StudentRegistration();

                            else if (choose == 'x' || choose == 'X')
                                AdminMenu();

                        }
                    }

                    cout << setw(89) << "Enter Faculty Code : ";
                    cin >> facultyCode;
                    cout << endl;

                    string checkMatricNo_query = "select * from faculty where facultyCode = '" + facultyCode + "'";
                    const char* cu = checkMatricNo_query.c_str();
                    qstate = mysql_query(conn, cu);
                    if (!qstate)
                    {
                        res = mysql_store_result(conn);

                        while (res->row_count == 0)
                        {
                            cout << endl;
                            cout << setw(113) << "Invalid Faculty Code! Please Re-enter : ";
                            cin >> facultyCode;

                            string checkMatricNo_query = "select * from faculty where facultyCode = '" + facultyCode + "'";
                            const char* cu = checkMatricNo_query.c_str();
                            qstate = mysql_query(conn, cu);
                            if (!qstate)
                                res = mysql_store_result(conn);


                        }
                        if (res->row_count == 1)
                        {
                            

                            cout << setw(81) << "Enter Name : ";
                            cin.ignore(1, '\n');
                            getline(cin,studentName);
                            cout << endl;

                            
                            cout << setw(82) << "Enter Email : ";
                            cin >> studentEmail;
                            cout << endl;
                            //cin.ignore(1, '\n');
                            // Function Call 
                            bool ans = isValid(studentEmail);

                            // Print the result 
                            while (ans == false)
                            {
                                cout << setw(125) << "Invalid student email! Student email must be <<matricNo>>@student.com "<<endl;
                                cout << setw(101) << "Please re-enter student email : ";
                                cin >> studentEmail;
                                ans = isValid(studentEmail);
                                cout << endl;

                            }
                           
                            if (ans) {

                                cout << setw(89) << "Enter Phone number : ";
                                cin >> studentPhoneNo;
                                cout << endl;

                                while ((studentPhoneNo.length() != 10) && (studentPhoneNo.length() != 11))
                                {
                                    
                                    cout << endl;
                                    cout << setw(115) << "Invalid lenght of Phone Number! Please enter 10-11 character of numbers  : ";
                                    cin >> studentPhoneNo;

                                }

                                cout << setw(89) << "Enter Semester (X/X) : ";
                                cin >> semester;

                                time_t t = time(nullptr);
                                tm local_time;
                                errno_t result = localtime_s(&local_time, &t);
                                string currDate = to_string(local_time.tm_year + 1900) + "-" + to_string(local_time.tm_mon + 1) + "-" + to_string(local_time.tm_mday);

                                //string insertCustomer_query = "insert into student (matricNo, facultyCode, studentPassword, roomNo, studentName, studentEmail, studentPhoneNo, semester) values ('" + matricNo + "', '" + facultyCode + "','" + studentPassword + "','" + roomNo + "', '" + studentName + "', '" + studentEmail + "', '" + studentPhoneNo + "', '" + semester + "')";
                                string insertStudent_query = "insert into student (matricNo, facultyCode, roomNo, studentName, studentEmail, studentPhoneNo, semester, dateRegister) values ('" + matricNo + "', '" + facultyCode + "','" + roomNo + "', '" + studentName + "', '" + studentEmail + "', '" + studentPhoneNo + "', '" + semester + "', '" + currDate + "')";

                                const char* q = insertStudent_query.c_str();
                                qstate = mysql_query(conn, q);

                                if (!qstate)
                                {
                                    cout << endl;
                                    cout << setw(113) << "Student have been registered. Press any key to Continue...";
                                    _getch();
                                    AdminMenu();
                                }
                                else
                                {
                                    cout << endl;
                                    cout << setw(110) << "Query Execution Problem!" << mysql_errno(conn) << endl;
                                }


                            }
                            


                        }

                       
                    }
                }
              
                else
                {
                cout << endl;
                cout << setw(98) << "Room does not exist! Please enter Y to search another room, X to cancel : ";
                cin >> choose;

                while ((choose != 'y' && choose != 'Y') && (choose != 'x' && choose != 'X'))
                {
                    cout << endl;
                    cout << setw(98) << "Wrong choice! Please choose either Y or X :  ";
                    cin >> choose;
                }
                if (choose == 'y' || choose == 'Y')
                    StudentRegistration();

                else if (choose == 'x' || choose == 'X')
                    AdminMenu();
                }

            }
            else
            cout << setw(98) << "Query Execution Problem!" << mysql_errno(conn) << endl;
        }

    }
    else
    cout << setw(98) << "Query Execution Problem!" << mysql_errno(conn) << endl;
}

                    
   
bool isValid(const string& studentEmail)
{

    // Regular expression definition 
    const regex pattern(
        "(\\w+10)(\\.|_)??(\\w*)@(student)(\\.(\\w+))+");

    // Match the string pattern 
    // with regular expression 
    return regex_match(studentEmail, pattern);
}

void RemoveStudent()
{
    system("cls");
    char choose;
    string matricNo, studentName;

    cout << endl;

    cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "------------------------------------------------------------------------------      STUDENT HOSTEL MANAGEMENT SYSTEM     ------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    // Get the current time in seconds
    time_t t = time(nullptr);

    // Convert the time value to a tm structure
    tm local_time;
    errno_t result = localtime_s(&local_time, &t);


    string currTime = to_string(local_time.tm_year + 1900) + "-" + to_string(local_time.tm_mon + 1) + "-" + to_string(local_time.tm_mday) + " " +
        to_string(local_time.tm_hour) + ":" + to_string(local_time.tm_min);

    cout << setw(100) << "Date and time now is : " << currTime << endl;
    cout << endl;
    cout << endl;
    cout << endl;

    cout << setw(107) << "--- Remove Student ---" << endl;
    cout << endl;

    string checkF_query = "select * from student";
    const char* cf = checkF_query.c_str();
    qstate = mysql_query(conn, cf);

    if (!qstate)
    {

        res = mysql_store_result(conn);
        if (res->row_count > 0)
        {
            cout << "\n";
            cout << "\t" << left << setw(105) << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

            cout << "\t" << left << setw(25) << "   MATRIC NUMBER" << setw(20) << "FACULTY CODE " << setw(50) << "   STUDENT NAME" << setw(30) << "  EMAIL" << setw(20) << "PHONE NUMBER" << setw(20) << "SEMESTER" << setw(20) << "REGISTER DATE" << setw(15) << "ROOM NUMBER" << endl;
            cout << "\t" << left << setw(105) << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            int i = 1;
            while (row = mysql_fetch_row(res))
            {
                cout << "\t" << left << setw(5) << i << setw(20) << row[0] << setw(20) << row[1] << setw(50) << row[3] << setw(30) << row[4] << setw(20) << row[5] << setw(20) << row[6] << setw(20) << row[7] << setw(13) << row[8] << endl;
                cout << endl;
                i++;
            }

            cout << endl;
            cout << endl;

            cout << right;
        }
    }
    cout << setw(96) << "Enter Student Matric Number : ";
    cin >> matricNo;
    string checkRoom_query = "select * from student where matricNo = '" + matricNo + "'";
    const char* cu = checkRoom_query.c_str();
    qstate = mysql_query(conn, cu);

    if (!qstate)
    {

        res = mysql_store_result(conn);
        while (res->row_count == 0)
        {
            cout << "\n\n";
            cout << setw(115) << "Matric Number does not exist!, Please re-enter Matric Number : ";
            cin >> matricNo;

            string checkRoom_query = "select * from student where matricNo = '" + matricNo + "'";
            const char* cu = checkRoom_query.c_str();
            qstate = mysql_query(conn, cu);

            if (!qstate)

                res = mysql_store_result(conn);

        }

        if (res->row_count == 1)
        {
            
                while (row = mysql_fetch_row(res))
                {
                    matricNo = row[0];
                    studentName = row[3];

                }
            cout << endl;
            cout << setw(70) << "Are you sure to remove " <<studentName<< "? Enter [Y - YES / X- Cancel] : ";
            cin >> choose;
            while ((choose != 'y' && choose != 'Y') && (choose != 'x' && choose != 'X'))
            {
                cout << setw(95) << "Wrong choice! Please choose either Y -yes or X - back to main menu :  ";
                cin >> choose;
            }

            if (choose == 'y' || choose == 'Y')
            {

                string del_query = "delete from appliance_registration where matricNo = '" + matricNo + "'";
                const char* d = del_query.c_str();
                qstate = mysql_query(conn, d);

                string de_query = "delete  from student where matricNo = '" + matricNo + "'";
                const char* q = de_query.c_str();
                qstate = mysql_query(conn, q);
                if (!qstate)
                {
                    cout << "\n\n";
                    cout << setw(97) << "Student has been removed! "<<endl;
                    cout << setw(125) << "Do you want to remove other student? Enter [Y - YES / X- CANCEL] : ";

                    cin >> choose;
                    while ((choose != 'y' && choose != 'Y') && (choose != 'x' && choose != 'X'))
                    {
                        cout << setw(95) << "Wrong choice! Please choose either Y -yes or X - back to main menu :  ";
                        cin >> choose;
                    }

                    if (choose == 'y' || choose == 'Y')
                        RemoveStudent();

                    else if (choose == 'x' || choose == 'X')
                        AdminMenu();
                }
            }

            else if (choose == 'x' || choose == 'X')
                RemoveStudent();
            
            else
                cout << setw(98) << "Query Execution Problem!" << mysql_errno(conn) << endl;
           
        }
       
    }

}
void AdminAppRegReceipt()
{
    system("cls");
    char choose;
    string appRegId, totalCharge, matricNo, studentName, roomNo;
  
    cout << endl;

    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "---------------------------------------------------------------      STUDENT HOSTEL MANAGEMENT SYSTEM     ------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    // Get the current time in seconds
    time_t t = time(nullptr);

    // Convert the time value to a tm structure
    tm local_time;
    errno_t result = localtime_s(&local_time, &t);


    string currTime = to_string(local_time.tm_year + 1900) + "-" + to_string(local_time.tm_mon + 1) + "-" + to_string(local_time.tm_mday) + " " +
        to_string(local_time.tm_hour) + ":" + to_string(local_time.tm_min);

    cout << setw(90) << "Date and time now is : " << currTime << endl;
    cout << endl;
    cout << endl;
    cout << endl;

    cout << setw(105) << "--- Electrical Appliance Receipt ---" << endl;
    cout << endl;
    cout << setw(96) << "Enter Student Matric Number : ";
    cin >> matricNo;
    string checkRoom_query = "select studentName, roomNo from student where matricNo = '" + matricNo + "'";
    const char* cu = checkRoom_query.c_str();
    qstate = mysql_query(conn, cu);

    if (!qstate)
    {

        res = mysql_store_result(conn);
        if (res->row_count == 1)
        {

            while (row = mysql_fetch_row(res))
            {
                studentName = row[0];
                roomNo = row[1];

            }
        }
    }

    /*   time_t t = time(nullptr);
       tm local_time;
       errno_t result = localtime_s(&local_time, &t);*/
    string currDate = to_string(local_time.tm_year + 1900) + "-" + to_string(local_time.tm_mon + 1) + "-" + to_string(local_time.tm_mday);
    string checkA = "SELECT appliance_registration.registerId, electrical_appliance.applianceType, electrical_appliance.applianceCharge , appliance_registration.appRegDate FROM appliance_registration INNER JOIN electrical_appliance ON appliance_registration.applianceCode=electrical_appliance.applianceCode where matricNo = '" + matricNo + "'";
    const char* x = checkA.c_str();
    qstate = mysql_query(conn, x);

    if (!qstate)
    {        
        res = mysql_store_result(conn);

        while (res->row_count == 0)
        {
            cout << setw(105) << "Matric Number not found! Please re-enter matric number  : ";
            cin >> matricNo;

            string checkA = "SELECT appliance_registration.registerId, electrical_appliance.applianceType, electrical_appliance.applianceCharge , appliance_registration.appRegDate FROM appliance_registration INNER JOIN electrical_appliance ON appliance_registration.applianceCode=electrical_appliance.applianceCode where matricNo = '" + matricNo + "'";
            const char* x = checkA.c_str();
            qstate = mysql_query(conn, x);

            if (!qstate)

                res = mysql_store_result(conn);

        }

        if (res->row_count > 1)
        {
            cout << endl;
            cout << endl;
            cout << setw(80) << "Student Name : " <<studentName<< endl;
            cout << setw(90) << "Room Number :" << roomNo << endl;
            cout << endl;
            cout << "\t\t\t\t\t\t" << left << setw(20) <<"REGISTRATION ID" << setw(20) << "APPLIANCE TYPE" << setw(23) << "APPLIANCE CHARGE(RM) " << setw(20) << "REGISTRATION DATE " << endl;
            cout <<  "\t\t\t\t\t\t=================================================================================" << endl;

            while (row = mysql_fetch_row(res))
            {
                cout << endl;
                cout <<"\t\t\t\t\t\t\t"<<left<< setw(15) << row[0] << setw(20) << row[1] << setw(20) << row[2] << setw(20) << row[3] << endl;

            }

            cout << right;
        }
       

        cout << endl;
        cout << endl;
        cout << setw(105) << "Do you want to continue search? [Y-yes, X-Cancel]  : ";
        cin >> choose;

        while ((choose != 'y' && choose != 'Y') && (choose != 'x' && choose != 'X'))
        {
            cout << setw(95) << "Wrong choice! Please choose either Y -yes or X - back to main menu :  ";
            cin >> choose;
        }

        if (choose == 'y' || choose == 'Y')
            AdminAppRegReceipt();

        else if (choose == 'x' || choose == 'X')
            AdminMenu();
    }          
    else
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;

}

void RoomItem()
{
   
    system("cls");
    string roomNo;
    char choose;
    int menuRoom;
    cout << endl;

    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "---------------------------------------------------------------      STUDENT HOSTEL MANAGEMENT SYSTEM     ------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    // Get the current time in seconds
    time_t t = time(nullptr);

    // Convert the time value to a tm structure
    tm local_time;
    errno_t result = localtime_s(&local_time, &t);


    string currTime = to_string(local_time.tm_year + 1900) + "-" + to_string(local_time.tm_mon + 1) + "-" + to_string(local_time.tm_mday) + " " +
        to_string(local_time.tm_hour) + ":" + to_string(local_time.tm_min);

    cout << setw(90) << "Date and time now is : " << currTime << endl;
    cout << endl;
    cout << endl;

    cout << setw(95) << "--- Room Item Menu ---" << endl;
    cout << endl;
    cout << setw(93) << "[1] Add Room Item " << endl << endl;
    cout << setw(96) << "[2] Delete Room Item " << endl << endl;
    cout << setw(97) << "[3] Display Room Item " << endl << endl;
    cout << setw(98) << "[4] Back to Admin menu " << endl << endl;

    cout  << endl;
    cout << setw(97) << "Please choose between [1-4] : ";

    cin >> menuRoom;

    switch (menuRoom)
    {
    case 1:
        AddRoomItem();
        break;
    case 2:
        DeleteRoomItem ();
        break;
    case 3:
        DisplayRoomItem();
        break;
    case 4:
        AdminMenu();
        break;
    /*case 4:
        AdminMenu();
        break;*/
    default:
        cout << setw(97) << "Please choose between 1 - 4. Press Any Key To Continue...";
        _getch();
        system("cls");
        RoomItem();
        break;
    }
}


void AddRoomItem() {
    system("cls");
    string roomNo, itemType,quantity;
    char choose;

    cout << endl;

    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "---------------------------------------------------------------      STUDENT HOSTEL MANAGEMENT SYSTEM     ------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    // Get the current time in seconds
    time_t t = time(nullptr);

    // Convert the time value to a tm structure
    tm local_time;
    errno_t result = localtime_s(&local_time, &t);


    string currTime = to_string(local_time.tm_year + 1900) + "-" + to_string(local_time.tm_mon + 1) + "-" + to_string(local_time.tm_mday) + " " +
        to_string(local_time.tm_hour) + ":" + to_string(local_time.tm_min);

    cout << setw(90) << "Date and time now is : " << currTime << endl;
    cout << endl;
    cout << endl;
     
    cout << setw(95) << "--- Add Room Item ---" << endl;
    cout << endl;
    cout << setw(95) << "Enter Room Number (X-XX-XX) : ";
    cin.ignore(1, '\n');
    getline(cin, roomNo);
    string checkRoom_query = "select * from room where roomNo = '" + roomNo + "'";
    const char* cu = checkRoom_query.c_str();
    qstate = mysql_query(conn, cu);

    if (!qstate)
    {
        res = mysql_store_result(conn);
        while (res->row_count == 0)
        {
            cout << endl;
            cout << setw(95) << "Room number does not exist. Please re-enter room number : ";
            cin >> roomNo;

            string checkRoom_query = "select * from room where roomNo = '" + roomNo + "'";
            const char* cu = checkRoom_query.c_str();
            qstate = mysql_query(conn, cu);

            if (!qstate)
                res = mysql_store_result(conn);
        }

        if (res->row_count == 1)
        {

            cout << setw(95) << "Enter Item Type: ";
            cin >> itemType;

            cout << setw(95) << "Enter Item Quantity : ";
            cin >> quantity;

            string insertItemRoom_query = "insert into room_item (roomNo, itemType, itemQuantity) values ('" + roomNo + "', '" + itemType + "', '" + quantity + "')";

            const char* q = insertItemRoom_query.c_str();
            qstate = mysql_query(conn, q);

            if (!qstate)
            {
                cout << setw(95) << "Room Item has been added. Press Y to add another item,  X to cancel : ";
                cin >> choose;

                while ((choose != 'y' && choose != 'Y') && (choose != 'x' && choose != 'X'))
                {
                    cout << setw(95) << "Wrong choice! Please choose either Y or X :  ";
                    cin >> choose;
                }

                if (choose == 'y' || choose == 'Y')
                    AddRoomItem();

                else if (choose == 'x' || choose == 'X')
                    RoomItem();
            }
            else
            {
                cout << setw(95) << "Query Execution Problem!" << mysql_errno(conn) << endl;
            }
        }
       
    }
            else
                cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
 }



void DisplayRoomItem() {

    system("cls");
    string roomNo;
    char choose;

    cout << endl;

    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "---------------------------------------------------------------      STUDENT HOSTEL MANAGEMENT SYSTEM     ------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    // Get the current time in seconds
    time_t t = time(nullptr);

    // Convert the time value to a tm structure
    tm local_time;
    errno_t result = localtime_s(&local_time, &t);


    string currTime = to_string(local_time.tm_year + 1900) + "-" + to_string(local_time.tm_mon + 1) + "-" + to_string(local_time.tm_mday) + " " +
        to_string(local_time.tm_hour) + ":" + to_string(local_time.tm_min);

    cout << setw(90) << "Date and time now is : " << currTime << endl;
    cout << endl;
    cout << endl;

    cout << setw(98) << "--- Room Item Details ---" << endl;
    cout << "\n\n";
    cout << setw(99) << "Enter Room Number (X-XX-XX) : ";
    cin.ignore(1, '\n');
    getline(cin, roomNo);
    string checkRoom_query = "select * from room_item where roomNo = '" + roomNo + "'";
    const char* cu = checkRoom_query.c_str();
    qstate = mysql_query(conn, cu);

    if (!qstate)
    {

        res = mysql_store_result(conn);
        while (res->row_count == 0)
        {
            cout << endl;
            cout << setw(95) << "Room number does not exist. Please re-enter room number : ";
            cin >> roomNo;

            string checkRoom_query = "select * from room_item where roomNo = '" + roomNo + "'";
            const char* cu = checkRoom_query.c_str();
            qstate = mysql_query(conn, cu);
            if (!qstate)
                res = mysql_store_result(conn);
        }
        if (res->row_count > 0)
        {
            cout << "\n\n";
            cout << setw(120) << "--------------------------------------------------------------" << endl;

            cout << setw(80) << "Item Id" << setw(13) << "Item Type" << setw(13) << "Quantity" << endl;
            cout << setw(120) << "--------------------------------------------------------------" << endl;

            while (row = mysql_fetch_row(res))
            {
                cout << "\t\t" << setw(64) << row[0] << setw(13) << row[2] << setw(13) << row[3] << endl;
            }

            cout << "\n\n";

            cout << setw(118) << "Press S to search next room, X to back to room item menu: ";
            cin >> choose;
            while ((choose != 's' && choose != 'S') && (choose != 'x' && choose != 'X'))
            {
                cout << setw(109) << "Wrong choice! Please choose either S or X :  ";
                cin >> choose;
            }

            if (choose == 's' || choose == 'S')
                DisplayRoomItem();

            else if (choose == 'x' || choose == 'X')
                RoomItem();

        }

        cout << "\n\n";
        cout << setw(108) << "Press S to search next room, X to back to room item menu: ";
        cin >> choose;
        while ((choose != 's' && choose != 'S') && (choose != 'x' && choose != 'X'))
        {
            cout << setw(108) << "Wrong choice! Please choose either S or X :  ";
            cin >> choose;
        }

        if (choose == 's' || choose == 'S')
            DisplayRoomItem();

        else if (choose == 'x' || choose == 'X')
            RoomItem();
    }
    else {
       // cout << "Room Not Found" << endl;
        cout << "Query Execution Problem" << mysql_errno << endl;

    }

}

void DeleteRoomItem()
{
    system("cls");
    string roomNo, itemId;
    char choose;

    cout << endl;

    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "---------------------------------------------------------------      STUDENT HOSTEL MANAGEMENT SYSTEM     ------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    // Get the current time in seconds
    time_t t = time(nullptr);

    // Convert the time value to a tm structure
    tm local_time;
    errno_t result = localtime_s(&local_time, &t);


    string currTime = to_string(local_time.tm_year + 1900) + "-" + to_string(local_time.tm_mon + 1) + "-" + to_string(local_time.tm_mday) + " " +
        to_string(local_time.tm_hour) + ":" + to_string(local_time.tm_min);

    cout << setw(90) << "Date and time now is : " << currTime << endl;
    cout << endl;
    cout << endl;


    cout << setw(95) << "--- Delete Room Item ---" << endl;
    cout << "\n\n";
    cout << setw(95) << "Enter Room Number (X-XX-XX) : ";
    cin.ignore(1, '\n');
    getline(cin, roomNo);
    string checkRoom_query = "select * from room_item where roomNo = '" + roomNo + "'";
    const char* cu = checkRoom_query.c_str();
    qstate = mysql_query(conn, cu);

    if (!qstate)
    {

        res = mysql_store_result(conn);
        while (res->row_count == 0)
        {
            cout << endl;
            cout << setw(95) << "Room number does not exist. Please re-enter room number : ";
            cin >> roomNo;

            string checkRoom_query = "select * from room_item where roomNo = '" + roomNo + "'";
            const char* cu = checkRoom_query.c_str();
            qstate = mysql_query(conn, cu);
            if (!qstate)
                res = mysql_store_result(conn);
        }

        if (res->row_count > 0)
        {
            cout << "\n\n";
            cout << setw(117) << "-----------------------------------------------------------" << endl;

            cout << setw(75) << "Item Id" << setw(15) << "Item Type" << setw(15) << "Quantity" << endl;
            cout << setw(117) << "-----------------------------------------------------------" << endl;

            while (row = mysql_fetch_row(res))
            {
                cout << "\t\t" << setw(60) << row[0] << setw(13) << row[2] << setw(13) << row[3] << endl;
            }

            cout << "\n\n";
            cout << setw(95) << "Enter Item Id to delete : ";
            getline(cin, itemId);

            string checkItem_query = "select * from room_item where itemId = '" + itemId + "'";
            const char* cu = checkItem_query.c_str();
            qstate = mysql_query(conn, cu);

            if (!qstate)
            {
                res = mysql_store_result(conn);
                while (res->row_count == 0)
                {
                    cout << "\n\n";
                    cout << setw(95) << "Incorrect room item id, Please re-enter room item id : ";
                    cin >> itemId;
                    string checkItem_query = "select * from room_item where itemId = '" + itemId + "'";
                    const char* cu = checkItem_query.c_str();
                    qstate = mysql_query(conn, cu);

                    if (!qstate)
                        res = mysql_store_result(conn);

                }
                if (res->row_count == 1)
                {
                    cout << "\n\n";
                    cout << setw(95) << "Are you sure to delete " << itemId << "? [Y-yes / N-no] :  ";
                    cin >> choose;

                    while ((choose != 'y' && choose != 'Y') && (choose != 'n' && choose != 'N'))
                    {
                        cout << setw(120) << "Wrong choice! Please choose either Y or N :  ";
                        cin >> choose;
                    }

                    if (choose == 'y' || choose == 'Y')
                    {
                        string del_query = "delete from item_report where itemId = '" + itemId + "'";
                        const char* d = del_query.c_str();
                        qstate = mysql_query(conn, d);

                        string delete_query = "delete  from room_item where itemId = '" + itemId + "'";
                        const char* q = delete_query.c_str();
                        qstate = mysql_query(conn, q);

                        cout << "\n\n";
                        cout << setw(115) << "Item has been deleted, do you want to delete other item? Enter [Y - YES / N- NO] : ";
                        cin.ignore(1, '\n');
                        cin >> choose;

                        while ((choose != 'y' && choose != 'Y') && (choose != 'n' && choose != 'N'))
                        {
                            cout << setw(95) << "Wrong choice! Please choose either Y or N :  ";
                            cin >> choose;
                        }

                        if (choose == 'y' || choose == 'Y')
                        {
                            DeleteRoomItem();
                        }
                        if (choose == 'n' || choose == 'N')
                            RoomItem();
                    }
                    if (choose == 'n' || choose == 'N')
                        DeleteRoomItem();
                }
               
            }

            else
                cout << setw(95) << "Query Execution Problem" << mysql_errno << endl;
        } 
       
    }
     else
        cout << setw(95) << "Query Execution Problem" << mysql_errno << endl;
}


void RoomItemReport()
{
    system("cls");
    string reportId;
    boolean choose;
    char menuReport;
    string status;

    string search_query = "select admin_id from admin where admin_id like '%" + adminID + "%'";
    const char* u = search_query.c_str();
    qstate = mysql_query(conn, u);

    if (!qstate)
    {
        res = mysql_store_result(conn);
        if (row = mysql_fetch_row(res))
        {
            adminID = row[0];
        }
    }


    cout << endl;

    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "---------------------------------------------------------------      STUDENT HOSTEL MANAGEMENT SYSTEM     ------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    // Get the current time in seconds
    time_t t = time(nullptr);

    // Convert the time value to a tm structure
    tm local_time;
    errno_t result = localtime_s(&local_time, &t);


    string currTime = to_string(local_time.tm_year + 1900) + "-" + to_string(local_time.tm_mon + 1) + "-" + to_string(local_time.tm_mday) + " " +
        to_string(local_time.tm_hour) + ":" + to_string(local_time.tm_min);

    cout << setw(90) << "Date and time now is : " << currTime << endl;
    cout << endl;
    cout << endl;

    cout << setw(96) << "--- Room Item Report ---" << endl;
    cout << "\n";

    string checkReport_query = "select * from item_report ";
    const char* cu = checkReport_query.c_str();
    qstate = mysql_query(conn, cu);

    if (!qstate)
    {
        res = mysql_store_result(conn);

        cout << endl;
        cout << "\t\t\t\t=================================================================================================================" << endl;
        cout << endl;
        cout << "\t\t\t\t\t"<<left<<setw(20) << "Report Id" << setw(20) << "Admin ID" << setw(20) << "Room No" << setw(20) << "Item Id" << setw(20) << "Report Date" << setw(20) << "Status" << endl;
        cout << endl;
        cout << "\t\t\t\t=================================================================================================================" << endl;
        cout << endl;
        while (row = mysql_fetch_row(res))
        {
            cout << "\t\t\t\t\t"<<left<<setw(20) << row[0] << setw(20) << row[1] << setw(20) << row[2] << setw(20) << row[3]  << setw(20) << row[5] << setw(20) << row[6] << endl;
        }

    }
    cout << right;

    cout << endl;
    cout << endl;

    cout << setw(99) << "[1] Display Report under "<< adminID << endl;
    cout << endl;
    cout << setw(91) << "[2] Update Report" << endl;
    cout << endl;
    cout << setw(91) << "[3] Delete Report" << endl;
    cout << endl;
    cout << setw(100) << "[4] Total Room Item Report" << endl;
    cout << endl;
    cout << setw(96) << "[5] Back to Admin Menu" << endl;
    cout << endl;
    cout << endl;
    cout << setw(105) << "Choose [1] / [2] / [3]  / [4] / [5] only :  ";

    cin >> menuReport;
    cin.ignore(1, '\n');

    if (menuReport == '1')
        DisplayRoomItemReport();

    else if (menuReport == '2')
        UpdateRoomItemReport();

    else if (menuReport == '3')
        DeleteRoomItemReport();

    else if (menuReport == '4')
        TotalReport();

    else if (menuReport == '5')
        AdminMenu();

    else {
        cout << endl;
        cout << setw(105) << "\t\tWrong choice! Please choose between [1-4] only. Press any key to continue... ";
        _getch();
        RoomItemReport();
    }
}
                    

void DisplayRoomItemReport()
{
    system("cls");
    char choose= '0';
    cout << endl;    
          
        cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << endl;
        cout << "-------------------------------------------------------------     WELCOME TO STUDENT HOSTEL MANAGEMENT SYSTEM     ----------------------------------------------------------------" << endl;
        cout << endl;
        cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << endl;
        cout << endl;
        time_t t = time(nullptr);

        // Convert the time value to a tm structure
        tm local_time;
        errno_t result = localtime_s(&local_time, &t);


        string currTime = to_string(local_time.tm_year + 1900) + "-" + to_string(local_time.tm_mon + 1) + "-" + to_string(local_time.tm_mday) + " " +
            to_string(local_time.tm_hour) + ":" + to_string(local_time.tm_min);

        cout << setw(90) << "Date and time now is : " << currTime << endl;
        cout << endl;
        cout << endl;

        string checkReportz_query = "select * from item_report where admin_id = '" + adminID + "'";
        const char* cuR= checkReportz_query.c_str();
        qstate = mysql_query(conn, cuR);

        if (!qstate)
        {
            res = mysql_store_result(conn);

            cout << endl;
            cout << "\t\t\t\t=======================================================================================================" << endl;
            cout << endl;
            cout << "\t\t\t\t\t" << left << setw(20) << "Report Id" << setw(20) << "Room No" << setw(20) << "Item Id" << setw(20) << "Report Date" << setw(20) << "Status" << endl;
            cout << endl;
            cout << "\t\t\t\t=======================================================================================================" << endl;
            cout << endl;
            while (row = mysql_fetch_row(res))
            {
                cout << "\t\t\t\t\t" << left << setw(20) << row[0] << setw(20) << row[2] << setw(20) << row[3] << setw(20) << row[5] << setw(20) << row[6] << endl;
            }

        }
        cout << right;

        cout << endl;
        cout << endl;

        string reportId;
        cout << setw(90) << "Enter report ID : ";
        cin >> reportId;
        
        system("cls");
        cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << endl;
        cout << "-------------------------------------------------------------     WELCOME TO STUDENT HOSTEL MANAGEMENT SYSTEM     ----------------------------------------------------------------" << endl;
        cout << endl;
        cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << endl;
        cout << endl;  

        cout << setw(93) << "Date and time now is : " << currTime << endl;
        cout << endl;
        cout << endl;


        string checkReport_query = "select * from item_report where reportId = '" + reportId + "'";
        const char* cu = checkReport_query.c_str();
        qstate = mysql_query(conn, cu);

        if (!qstate)
        {
            res = mysql_store_result(conn);
            if (res->row_count == 1)
            {
                cout << "\t\t\t\t\t\t\t\t\t================================" << endl;

                cout << endl;
                cout << setw(85) << "---   Report " << reportId << " Details  ---" << endl;
                cout << endl;
                cout << "\t\t\t\t\t\t\t\t\t================================" << endl;
                while (row = mysql_fetch_row(res)) // looping to retrieve data
                {

                    cout << "\n";
                    cout << setw(87) << "Report ID     : " << row[0] << "  (Uneditable) ";
                    cout << "\n";
                    cout << "\n";
                    cout << setw(87) << "Room Number   : " << row[2] << endl;
                    cout << endl;
                    cout << setw(87) << "Item ID       : " << row[3] << endl;
                    cout << endl;
                    cout << setw(87) << "Report Date   : " << row[5] << endl;
                    cout << endl;
                    cout << setw(87) << "Description   : " << row[4] << endl;
                    cout << endl;
                    cout << setw(87) << "Report Status : " << row[6] << endl;
                    cout << endl;
                    cout << setw(87) << "Admin ID      : " << row[1] << endl;
                    cout << endl;

                }

                cout << "\n";

                cout << setw(108) << "Do you want to search another report? [Y to continue, X to cancel] : ";
                cin >> choose;

                while ((choose != 'y' && choose != 'Y') && (choose != 'x' && choose != 'X'))
                {
                    cout << endl;
                    cout << setw(90) << "Wrong choice! Please choose either Y or X :  ";
                    cin >> choose;
                }

                if (choose == 'y' || choose == 'Y')
                {
                    DisplayRoomItemReport();
                }

                else if (choose == 'x' || choose == 'X')
                {
                    RoomItemReport();
                }

            }

            else
            {
                cout << endl;
                cout << setw(90) << "Please enter the correct Report Id! Do you want to try again? [Y to continue, X to cancel] :";
                cin >> choose;

                while ((choose != 'y' && choose != 'Y') && (choose != 'x' && choose != 'X'))
                {
                    cout << endl;
                    cout << setw(90) << "Wrong choice! Please choose either Y or X :  ";
                    cin >> choose;
                }

                if (choose == 'y' || choose == 'Y')
                {
                    DisplayRoomItemReport();
                }

                else if (choose == 'x' || choose == 'X')
                {
                    RoomItemReport();
                }

            }
        }
        else
            cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
 }

void UpdateRoomItemReport()
{

    char choose;
    string status;
    system("cls");
    string reportId;
    int chooseUpdate = 0;

    string search_query = "select admin_id from admin where admin_id like '%" + adminID + "%'";
    const char* u = search_query.c_str();
    qstate = mysql_query(conn, u);

    if (!qstate)
    {
        res = mysql_store_result(conn);
        if (row = mysql_fetch_row(res))
        {
            adminID = row[0];
        }
    }


    cout << endl;

    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "-------------------------------------------------------------     WELCOME TO STUDENT HOSTEL MANAGEMENT SYSTEM     ----------------------------------------------------------------" << endl;
    cout << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << endl;

    // Get the current time in seconds
    time_t t = time(nullptr);

    // Convert the time value to a tm structure
    tm local_time;
    errno_t result = localtime_s(&local_time, &t);


    string currTime = to_string(local_time.tm_year + 1900) + "-" + to_string(local_time.tm_mon + 1) + "-" + to_string(local_time.tm_mday) + " " +
        to_string(local_time.tm_hour) + ":" + to_string(local_time.tm_min);

    cout << setw(90) << "Date and time now is : " << currTime << endl;
    cout << endl;
    cout << endl;

    cout << setw(100) << "--- Update Room Item Report ---" << endl;
    cout << "\n";

    string checkReport_query = "select * from item_report ";
    const char* cu = checkReport_query.c_str();
    qstate = mysql_query(conn, cu);

    if (!qstate)
    {
        res = mysql_store_result(conn);

        cout << endl;
        cout << "\t\t\t\t\t=======================================================================================================" << endl;
        cout << endl;
        cout << setw(53) << "Report Id" << setw(13) << "Admin Id" << setw(13) << "Room No" << setw(13) << "Item Id" << setw(20) << "Report Date" << setw(18) << "Status" << endl;
        cout << endl;
        cout << "\t\t\t\t\t=======================================================================================================" << endl;
        cout << endl;
        while (row = mysql_fetch_row(res))
        {
            cout << setw(51) << row[0] << setw(13) << row[1] << setw(13) << row[2] << setw(13) << row[3] << setw(20) << row[5] << setw(18) << row[6] << endl;
        }

    }

    cout << endl;
    cout << endl;

    cout << setw(92) << "Enter report ID : ";
    cin >> reportId;

    string search_report = "select reportId, admin_id, roomNo, itemId, reportDate, status, description from item_report where reportId = '" + reportId + "'";
    const char* q = search_report.c_str();
    qstate = mysql_query(conn, q);
    res = mysql_store_result(conn);

    if (res->row_count == 1)
    {
        cout << endl;
        cout << setw(96) << "Insert new report status : ";
        cin.ignore(1, '\n');
        getline(cin, status);

        string update_product = "update item_report set status = '" + status + "', admin_id ='" + adminID + "' where reportId = '" + reportId + "'";
        const char* q = update_product.c_str();
        qstate = mysql_query(conn, q);
        cout << endl;
        
        string checkReport_query = "select * from item_report ";
        const char* cu = checkReport_query.c_str();
        qstate = mysql_query(conn, cu);

        if (!qstate)
        {
            res = mysql_store_result(conn);
            system("cls");

            cout << endl;

            cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            cout << endl;
            cout << "-------------------------------------------------------------     WELCOME TO STUDENT HOSTEL MANAGEMENT SYSTEM     ----------------------------------------------------------------" << endl;
            cout << endl;
            cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            cout << endl;
            cout << endl;
            cout << setw(90) << "Date and time now is : " << currTime << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            cout << "\t\t\t\t\t=======================================================================================================" << endl;
            cout << endl;
            cout << setw(53) << "Report Id" << setw(13) << "Admin Id" << setw(13) << "Room No" << setw(13) << "Item Id" << setw(20) << "Report Date" << setw(18) << "Status" << endl;
            cout << endl;
            cout << "\t\t\t\t\t=======================================================================================================" << endl;
            cout << endl;
            while (row = mysql_fetch_row(res))
            {
                cout << setw(51) << row[0] << setw(13) << row[1] << setw(13) << row[2] << setw(13) << row[3] << setw(20) << row[5] << setw(18) << row[6] << endl;
            }

        }

        cout << "\n";
        cout << setw(97) << "Report status successfully updated! Press [ Y to continue update report.. X to cancel] :";
        cin >> choose;

        while ((choose != 'y' && choose != 'Y') && (choose != 'x' && choose != 'X'))
        {
            cout << endl;
            cout << setw(90) << "Wrong choice! Please choose either Y or X :  ";
            cin >> choose;
        }

        if (choose == 'y' || choose == 'Y')
        {
            UpdateRoomItemReport();
        }

        else if (choose == 'x' || choose == 'X')
        {
            RoomItemReport();
        }
    }
    else
    {
        cout << endl;
        cout << setw(150) << "Incorrect Report Id! Press [S to search again , X to cancel] : ";
        cin >> choose;

        while ((choose != 's' && choose != 'S') && (choose != 'x' && choose != 'X'))
        {
            cout << endl;
            cout << setw(150) << "Wrong choice! Please choose either S or X :  ";
            cin >> choose;
        }

        if (choose == 's' || choose == 'S')
            UpdateRoomItemReport();

        else if (choose == 'x' || choose == 'X')
            RoomItemReport();


    }


}

void DeleteRoomItemReport() 
{
   
    string roomNo, itemId;
    char choose;

    system("cls");
    string reportId;
    int chooseUpdate = 0;
    string status;

    string search_query = "select admin_id from admin where admin_id like '%" + adminID + "%'";
    const char* u = search_query.c_str();
    qstate = mysql_query(conn, u);

    if (!qstate)
    {
        res = mysql_store_result(conn);
        if (row = mysql_fetch_row(res))
        {
            adminID = row[0];
        }
    }


    cout << endl;

    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "-------------------------------------------------------------     WELCOME TO STUDENT HOSTEL MANAGEMENT SYSTEM     ----------------------------------------------------------------" << endl;
    cout << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << endl;
    // Get the current time in seconds
    time_t t = time(nullptr);

    // Convert the time value to a tm structure
    tm local_time;
    errno_t result = localtime_s(&local_time, &t);


    string currTime = to_string(local_time.tm_year + 1900) + "-" + to_string(local_time.tm_mon + 1) + "-" + to_string(local_time.tm_mday) + " " +
        to_string(local_time.tm_hour) + ":" + to_string(local_time.tm_min);

    cout << setw(90) << "Date and time now is : " << currTime << endl;
    cout << endl;
    cout << endl;

    cout << setw(100) << "--- Delete Room Item Report ---" << endl;
    cout << "\n";

    string checkReport_query = "select * from item_report ";
    const char* cu = checkReport_query.c_str();
    qstate = mysql_query(conn, cu);

    if (!qstate)
    {
        res = mysql_store_result(conn);

        cout << endl;
        cout << "\t\t\t\t\t=======================================================================================================" << endl;
        cout << endl;
        cout << setw(53) << "Report Id" << setw(13) << "Admin Id" << setw(13) << "Room No" << setw(13) << "Item Id" << setw(20) << "Report Date" << setw(18) << "Status" << endl;
        cout << endl;
        cout << "\t\t\t\t\t=======================================================================================================" << endl;
        cout << endl;
        while (row = mysql_fetch_row(res))
        {
            cout << setw(51) << row[0] << setw(13) << row[1] << setw(13) << row[2] << setw(13) << row[3] << setw(20) << row[5] << setw(18) << row[6] << endl;
        }

    }

    cout << endl;

    cout << setw(97) << "Enter report Id to delete : ";
    cin >> reportId;

    string checkRt_query = "select * from item_report where reportId = '" + reportId + "'";
    const char* ch = checkRt_query.c_str();
    qstate = mysql_query(conn, ch);

    if (!qstate)
    {
        res = mysql_store_result(conn);

        if (res->row_count == 1)
        {
            cout << endl;
            cout << setw(93) << "Are you confirm to delete " << reportId <<"? Enter [Y to continue, X to cancel] : ";
            cin >> choose;

            while ((choose != 'y' && choose != 'Y') && (choose != 'x' && choose != 'X'))
            {
                cout << endl;
                cout << setw(90) << "Wrong choice! Please choose either Y or X :  ";
                cin >> choose;
            }

            if (choose == 'y' || choose == 'Y')
            {

                string delete_query = "delete from item_report where reportId = '" + reportId + "'";
                const char* q = delete_query.c_str();
                qstate = mysql_query(conn, q);

                system("cls");
                cout << endl;


                cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                cout << endl;
                cout << "-------------------------------------------------------------     WELCOME TO STUDENT HOSTEL MANAGEMENT SYSTEM     ----------------------------------------------------------------" << endl;
                cout << endl;
                cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                cout << endl;
                cout << endl;
                // Get the current time in seconds
                time_t t = time(nullptr);

                // Convert the time value to a tm structure
                tm local_time;
                errno_t result = localtime_s(&local_time, &t);


                string currTime = to_string(local_time.tm_year + 1900) + "-" + to_string(local_time.tm_mon + 1) + "-" + to_string(local_time.tm_mday) + " " +
                    to_string(local_time.tm_hour) + ":" + to_string(local_time.tm_min);

                cout << setw(90) << "Date and time now is : " << currTime << endl;
                cout << endl;
                cout << endl;

                cout << setw(100) << "--- Delete Room Item Report ---" << endl;
                cout << "\n";

                string checkReport_query = "select * from item_report ";
                const char* cu = checkReport_query.c_str();
                qstate = mysql_query(conn, cu);

                if (!qstate)
                {
                    res = mysql_store_result(conn);

                    cout << endl;
                    cout << "\t\t\t\t\t=======================================================================================================" << endl;
                    cout << endl;
                    cout << setw(53) << "Report Id" << setw(13) << "Admin Id" << setw(13) << "Room No" << setw(13) << "Item Id" << setw(20) << "Report Date" << setw(18) << "Status" << endl;
                    cout << endl;
                    cout << "\t\t\t\t\t=======================================================================================================" << endl;
                    cout << endl;
                    while (row = mysql_fetch_row(res))
                    {
                        cout << setw(51) << row[0] << setw(13) << row[1] << setw(13) << row[2] << setw(13) << row[3] << setw(20) << row[5] << setw(18) << row[6] << endl;
                    }

                }
                cout << endl;
                cout << setw(110) << "Report has been deleted! Do you want to delete another report? Enter [Y to continue, X to cancel] : ";
                cin >> choose;

                while ((choose != 'y' && choose != 'Y') && (choose != 'x' && choose != 'X'))
                {
                    cout << endl;
                    cout << setw(90) << "Wrong choice! Please choose either Y or X :  ";
                    cin >> choose;
                }

                if (choose == 'y' || choose == 'Y')
                {
                    DeleteRoomItemReport();
                }

                else if (choose == 'x' || choose == 'X')
                {
                    RoomItemReport();
                }
            }
            else if (choose == 'x' || choose == 'X')
            {
                RoomItemReport();
            }
            
        }

        else
        {
            cout << setw(97) << "Wrong Report Id! Do you want to try again?, Press [Y to continue, X to cancel]  : ";
            cin >> choose;

            while ((choose != 'y' && choose != 'Y') && (choose != 'x' && choose != 'X'))
            {
                cout << setw(97) << "Wrong choice! Please choose either Y or X :  ";
                cin >> choose;
            }

            if (choose == 'y' || choose == 'Y')
            {
                DeleteRoomItemReport();
            }
                   
            else if (choose == 'x' || choose == 'X')
                RoomItemReport();

        }

                  
    }
    else
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
}

void TotalReport()
{
    system("cls");
    string reportId, totalReport;
    boolean choose;
    char chooseUpdate;
    string status;


    cout << endl;

    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "---------------------------------------------------------------      STUDENT HOSTEL MANAGEMENT SYSTEM     ------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    // Get the current time in seconds
    time_t t = time(nullptr);

    // Convert the time value to a tm structure
    tm local_time;
    errno_t result = localtime_s(&local_time, &t);


    string currTime = to_string(local_time.tm_year + 1900) + "-" + to_string(local_time.tm_mon + 1) + "-" + to_string(local_time.tm_mday) + " " +
        to_string(local_time.tm_hour) + ":" + to_string(local_time.tm_min);

    cout << setw(90) << "Date and time now is : " << currTime << endl;
    cout << endl;
    cout << endl;

    cout << setw(100) << "--- Room Item Report ---" << endl;
    cout << "\n";

    string totalStudT_query = "select count(reportId) as totalReport from item_report ";
    const char* cuTR = totalStudT_query.c_str();
    qstate = mysql_query(conn, cuTR);

    if (!qstate)
    {
        res = mysql_store_result(conn);
        while (row = mysql_fetch_row(res))
        {
            totalReport = row[0];
        }
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }
    cout << endl;

    string checkReport_query = "select * from item_report";
    const char* cu = checkReport_query.c_str();
    qstate = mysql_query(conn, cu);

    if (!qstate)
    {
        res = mysql_store_result(conn);

        cout << setw(98) << "Total Room Item Report = " << totalReport;
        cout << endl;
        cout << endl;

        cout << endl;
        cout << "\t\t\t\t\t===========================================================================================================" << endl;
        cout << endl;
        cout << "\t\t\t\t\t" << left << setw(20) << "Report Id" << setw(20) << "Admin Id" << setw(20) << "Room No" << setw(20) << "Item Id" << setw(20) << "Report Date" << setw(20) << "Status" << endl;
        cout << endl;
        cout << "\t\t\t\t\t===========================================================================================================" << endl;
        cout << endl;

        int i = 1;
        while (row = mysql_fetch_row(res))
        {
            cout << "\t\t\t\t" << setw(3) << i << left <<" \t" <<setw(20) << row[0] << setw(20) << row[1] << setw(20) << row[2] << setw(20) << row[3] << setw(20) << row[5] << setw(20) << row[6] << endl;
            i++;
        }

    }

    cout << endl;
    cout << endl;
    cout << right;
    cout << "\t\t\t\t\t\t\t\t\tPress any key go to back to Room Item menu ...";
    _getch();

    RoomItemReport();

}


void StudentReportQuery()
{
    system("cls");
    string roomNo;
    char choose;
    int menuQuery;
    cout << endl;

    cout << endl;

    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "---------------------------------------------------------------      STUDENT HOSTEL MANAGEMENT SYSTEM     ------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    // Get the current time in seconds
    time_t t = time(nullptr);

    // Convert the time value to a tm structure
    tm local_time;
    errno_t result = localtime_s(&local_time, &t);


    string currTime = to_string(local_time.tm_year + 1900) + "-" + to_string(local_time.tm_mon + 1) + "-" + to_string(local_time.tm_mday) + " " +
        to_string(local_time.tm_hour) + ":" + to_string(local_time.tm_min);

    cout << setw(90) << "Date and time now is : " << currTime << endl;
    cout << endl;
    cout << endl;

    cout << setw(96) << "--- Report Query ---" << endl;
    cout << endl;
    cout << setw(101) << "[1] List of Student by Faculty" << endl << endl;
    cout << setw(100) << "[2] List of Student by Block " << endl << endl;
    cout << setw(99) << "[3] List of Student by Level" << endl << endl;
    cout << setw(105) << "[4] List of Student by Room Number" << endl << endl;
    cout << setw(94) << "[5] Back to Admin Menu " << endl << endl;

    cout << endl;
    cout << setw(102) << "Please choose between [1-5]: ";

    cin >> menuQuery;

    switch (menuQuery)
    {
    case 1:
        StudentFaculty();
        break;
    case 2:
        StudentBlock();
        break;
    case 3:
         StudentLevel();
        break;
    case 4:
         StudentRoom();
        break;
    case 5:
        AdminMenu();
        break;
    default:
        cout << setw(104) << "Please choose between [1 - 5] only . Press Any key To Continue...";
        _getch();
        system("cls");
        StudentReportQuery();
        break;
    }
    
}

void StudentFaculty() 
{
    system("cls");
    string facultyCode, totalStudentFaculty, totalStudent, facultyName;
    double studentPercentage;
    char choose;

    cout << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "-------------------------------------------------------------------------      STUDENT HOSTEL MANAGEMENT SYSTEM     --------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    // Get the current time in seconds
    time_t t = time(nullptr);

    // Convert the time value to a tm structure
    tm local_time;
    errno_t result = localtime_s(&local_time, &t);


    string currTime = to_string(local_time.tm_year + 1900) + "-" + to_string(local_time.tm_mon + 1) + "-" + to_string(local_time.tm_mday) + " " +
        to_string(local_time.tm_hour) + ":" + to_string(local_time.tm_min);

    cout << setw(98) << "Date and time now is : " << currTime << endl;
    cout << endl;
    cout << endl;

    cout << setw(111) << "--- List of Students By Faculty ---" << endl;
    cout << "\n\n";
    cout << setw(102) << "Enter Faculty Code : ";
    cin.ignore(1, '\n');
    getline(cin, facultyCode);

    string totalStudFp_query = "select count(facultyCode) as totalStudentFaculty from student where facultyCode = '" + facultyCode + "'";
    const char* cuP = totalStudFp_query.c_str();
    qstate = mysql_query(conn, cuP);

    if (!qstate)
    {
        res = mysql_store_result(conn);
        while (row = mysql_fetch_row(res))
        {
            totalStudentFaculty = row[0];
        }
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    string totalStudF_query = "select count(matricNo) as totalStudent from student";
    const char* cu = totalStudF_query.c_str();
    qstate = mysql_query(conn, cu);

    if (!qstate)
    {
        res = mysql_store_result(conn);
        while (row = mysql_fetch_row(res))
        {
            totalStudent = row[0];
        }
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    studentPercentage = (stod(totalStudentFaculty)/stod(totalStudent))*100;

   
    string checkStudent_query = "select facultyName from faculty where facultyCode = '" + facultyCode + "'";
    const char* cuAd = checkStudent_query.c_str();
    qstate = mysql_query(conn, cuAd);
    if (!qstate)
    {
        res = mysql_store_result(conn);
        if (res->row_count == 1)
        {
            while (row = mysql_fetch_row(res))
            {
                facultyName = row[0];

            }
        }
    }

    

    string checkF_query = "select * from student where facultyCode = '" + facultyCode + "'";
    const char* cf = checkF_query.c_str();
    qstate = mysql_query(conn, cf);

    if (!qstate)
    {

        res = mysql_store_result(conn);
        if (res->row_count > 0)

        {
            cout << endl;

            cout << setw(100) << "Total student from " << facultyCode << " = " << totalStudentFaculty << endl;
            cout << setw(91) << "Percentage of " << facultyCode << " student is " << studentPercentage << " %";
            cout << endl;
            cout << endl;
            
            cout << setw(115) << facultyName;
            cout << "\n";
            cout << "\t"<<left<< setw(105) << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

            cout << "\t"<<left<< setw(25) << "   MATRIC NUMBER" << setw(50) << "   STUDENT NAME" << setw(30) << "  EMAIL" << setw(20) << "PHONE NUMBER" << setw(20) << "SEMESTER" << setw(20) << "REGISTER DATE" << setw(15) << "ROOM NUMBER" << endl;
            cout << "\t"<<left<< setw(105) << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            int i=1;
            while (row = mysql_fetch_row(res))
            {
                cout << "\t" << left << setw(5) <<i<< setw(20) << row[0] << setw(50) << row[3] << setw(30) << row[4] << setw(20) << row[5] << setw(20) << row[6] << setw(20) << row[7] << setw(13) << row[8] << endl;
                cout << endl;
                i++;
            }

            cout << endl;
            cout << endl;

            cout<<right;
            
        }
        else
        {
            cout << endl;
            cout << setw(107) << "Faculty does not exist! Do you want to try again? [Y to continue, X to cancel] : ";
            cin >> choose;

            while ((choose != 'y' && choose != 'Y') && (choose != 'x' && choose != 'X'))
            {
                cout << setw(97) << "Wrong choice! Please choose either Y or X :  ";
                cin >> choose;
            }

            if (choose == 'y' || choose == 'Y')
            {
                StudentFaculty();
            }

            else if (choose == 'x' || choose == 'X')
                StudentReportQuery();
        }

        cout << endl;
        cout << setw(109) << "Do you want to search for another faculty ? [Y to continue, X to cancel] : ";
        cin >> choose;

        while ((choose != 'y' && choose != 'Y') && (choose != 'x' && choose != 'X'))
        {
            cout << setw(97) << "Wrong choice! Please choose either Y or X :  ";
            cin >> choose;
        }

        if (choose == 'y' || choose == 'Y')
        {
            StudentFaculty();
        }

        else if (choose == 'x' || choose == 'X')
            StudentReportQuery();
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

}

void StudentBlock()
{

    system("cls");
    string block, totalStudentBlock, totalRoom;
    int totalRoomAvailable;
    char choose;

    cout << endl;
    cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "-----------------------------------------------------------------------------      STUDENT HOSTEL MANAGEMENT SYSTEM     -------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    // Get the current time in seconds
    time_t t = time(nullptr);

    // Convert the time value to a tm structure
    tm local_time;
    errno_t result = localtime_s(&local_time, &t);


    string currTime = to_string(local_time.tm_year + 1900) + "-" + to_string(local_time.tm_mon + 1) + "-" + to_string(local_time.tm_mday) + " " +
        to_string(local_time.tm_hour) + ":" + to_string(local_time.tm_min);

    cout << setw(105) << "Date and time now is : " << currTime << endl;
    cout << endl;
    cout << endl;

    cout << setw(118) << "--- List of Students By Block ---" << endl;
    cout << "\n\n";
    cout << setw(106) << "Enter Block : ";
    cin.ignore(1, '\n');
    getline(cin, block);

    string totalStudF_query = "select count(room.block) as totalStudentBlock from student INNER JOIN room On student.roomNo = room.roomNo where room.block = '" + block + "'";
    const char* cuF = totalStudF_query.c_str();
    qstate = mysql_query(conn, cuF);

    if (!qstate)
    {
        res = mysql_store_result(conn);
        while (row = mysql_fetch_row(res))
        {
            totalStudentBlock = row[0];
        }
        cout << endl;

    }

    string totalStudFB_query = "select count(block) as totalRoom from room where block = '" + block + "'";
    const char* cuFB = totalStudFB_query.c_str();
    qstate = mysql_query(conn, cuFB);

    if (!qstate)
    {
        res = mysql_store_result(conn);
        while (row = mysql_fetch_row(res))
        {
            totalRoom = row[0];
        }
        cout << endl;
        totalRoomAvailable = (stoi(totalRoom)*2)-stoi(totalStudentBlock);
       
    }
    

    string checkRoom_query = "SELECT student.matricNo, student.studentName, student.studentEmail, student.studentPhoneNo, student.semester, student.dateRegister, student.roomNo, room.level , room.block from student INNER JOIN room ON student.roomNo = room.roomNo where room.block = '" + block + "'";
    const char* cu = checkRoom_query.c_str();
    qstate = mysql_query(conn, cu);

    if (!qstate)
    {

        res = mysql_store_result(conn);
        if (res->row_count > 1)
        {
            cout << endl;
            cout << setw(111) << "Room available in Block " << block << " = " << totalRoomAvailable;
            cout << endl;

            cout << setw(112) << "Total student from Block " << block << " = " << totalStudentBlock;
            cout << endl;
            cout << "\n";
            cout << "\t" << left << setw(105) << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

            cout << "\t" << left << setw(25) << "   MATRIC NUMBER" << setw(50) << "   STUDENT NAME" << setw(30) << "  EMAIL" << setw(20) << "PHONE NUMBER" << setw(20) << "SEMESTER" << setw(20) << "REGISTER DATE" << setw(20) << "ROOM NUMBER" << setw(10) << "LEVEL" << endl;
            cout << "\t" << left << setw(105) << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            int i = 1;
            while (row = mysql_fetch_row(res))
            {
                cout << "\t" << left << setw(5) << i << setw(20) << row[0] << setw(50) << row[1] << setw(30) << row[2] << setw(20) << row[3] << setw(20) << row[4] << setw(20) << row[5] << setw(20) << row[6] << setw(10) << row[7] << endl;
                cout << endl;
                i++;
            }

            cout << endl;
            cout << endl;

            cout << right;

        }
        else
        {
            cout << setw(97) << "Block does not exist! Enter [Y to continue... X to cancel] : ";
            cin >> choose;

            while ((choose != 'y' && choose != 'Y') && (choose != 'x' && choose != 'X'))
            {
                cout << setw(97) << "Wrong choice! Please choose either Y or X :  ";
                cin >> choose;
            }

            if (choose == 'y' || choose == 'Y')
            {
                StudentBlock();
            }

            else if (choose == 'x' || choose == 'X')
                StudentReportQuery();
        }
        cout << endl;
        cout << setw(109) << "Do you want to search for another block ? [Y to continue, X to cancel] : ";
        cin >> choose;

        while ((choose != 'y' && choose != 'Y') && (choose != 'x' && choose != 'X'))
        {
            cout << setw(97) << "Wrong choice! Please choose either Y or X :  ";
            cin >> choose;
        }

        if (choose == 'y' || choose == 'Y')
        {
            StudentBlock();
        }

        else if (choose == 'x' || choose == 'X')
            StudentReportQuery();
    
    }

    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }
}
        

       
   
void StudentLevel()
{

    system("cls");
    string block, level, totalStudentLevel, totalRoom;
    int totalRoomAvailable;
    char choose;

    cout << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "--------------------------------------------------------------------------------      STUDENT HOSTEL MANAGEMENT SYSTEM     -----------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    // Get the current time in seconds
    time_t t = time(nullptr);

    // Convert the time value to a tm structure
    tm local_time;
    errno_t result = localtime_s(&local_time, &t);


    string currTime = to_string(local_time.tm_year + 1900) + "-" + to_string(local_time.tm_mon + 1) + "-" + to_string(local_time.tm_mday) + " " +
        to_string(local_time.tm_hour) + ":" + to_string(local_time.tm_min);

    cout << setw(104) << "Date and time now is : " << currTime << endl;
    cout << endl;
    cout << endl;

    cout << setw(117) << "--- List of Students By Level ---" << endl;
    cout << "\n\n";
    cout << setw(104) << "Enter Block : ";
    cin.ignore(1, '\n');
    getline(cin, block);

    cout << setw(104) << "Enter Level : ";
    //cin.ignore(1, '\n');
    getline(cin, level);

    string totalStudF_query = "select count(room.level) as totalStudentLevel from student INNER JOIN room On student.roomNo = room.roomNo where room.block = '" + block + "' and room.level = '" + level + "' ";
    const char* cuL = totalStudF_query.c_str();
    qstate = mysql_query(conn, cuL);

    if (!qstate)
    {
        res = mysql_store_result(conn);
        while (row = mysql_fetch_row(res))
        {
            totalStudentLevel = row[0];
        }
  
    }
    else
            cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
        
    
    
    string totalStudFB_query = "select count(level) as totalRoom from room where level = '" + level + "'and block = '" + block + "' ";
    const char* cuFB = totalStudFB_query.c_str();
    qstate = mysql_query(conn, cuFB);

    if (!qstate)
    {
        res = mysql_store_result(conn);
        while (row = mysql_fetch_row(res))
        {
            totalRoom = row[0];
        }
        cout << endl;
        totalRoomAvailable = (stoi(totalRoom) * 2) - stoi(totalStudentLevel);
        
       
    }

    string checkRoom_query = "SELECT student.matricNo, student.studentName, student.studentEmail, student.studentPhoneNo, student.semester, student.dateRegister, student.roomNo, room.level , room.block from student INNER JOIN room ON student.roomNo = room.roomNo where room.block = '" + block + "' and room.level = '" + level+ "'";
    const char* cu = checkRoom_query.c_str();
    qstate = mysql_query(conn, cu);

    if (!qstate)
    {

        res = mysql_store_result(conn);
        if (res->row_count > 0)
        {
            cout << endl;
            cout << setw(107) << "Total student from Block " << block << " , Level " << level << " = " << totalStudentLevel;
            cout << endl;
            cout << setw(111) << "Room available in Level " << level << " = " << totalRoomAvailable;
            cout << endl;

            cout << "\n";
            cout << "\t" << left << setw(105) << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

            cout << "\t" << left << setw(25) << "   MATRIC NUMBER" << setw(50) << "   STUDENT NAME" << setw(30) << "  EMAIL" << setw(20) << "PHONE NUMBER" << setw(20) << "SEMESTER" << setw(20) << "REGISTER DATE" << setw(20) << "ROOM NUMBER" << setw(10) << "LEVEL" << endl;
            cout << "\t" << left << setw(105) << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            int i = 1;
            while (row = mysql_fetch_row(res))
            {
                cout << "\t" << left << setw(5) << i << setw(20) << row[0] << setw(50) << row[1] << setw(30) << row[2] << setw(20) << row[3] << setw(20) << row[4] << setw(20) << row[5] << setw(20) << row[6] << setw(10) << row[7] << endl;
                cout << endl;
                i++;
            }

            cout << endl;
            cout << endl;

            cout << right;
        }
        else
        {
            cout << endl;
            cout << setw(97) << "Block or Level does not exist! Do you want to try again? [Y to continue, X to cancel ] : ";
            cin >> choose;

            while ((choose != 'y' && choose != 'Y') && (choose != 'x' && choose != 'X'))
            {
                cout << setw(97) << "Wrong choice! Please choose either Y or X :  ";
                cin >> choose;
            }

            if (choose == 'y' || choose == 'Y')
            {
                StudentLevel();
            }

            else if (choose == 'x' || choose == 'X')
                StudentReportQuery();
        }

        cout << endl;
        cout << setw(109) << "Do you want to search for another level ? [Y to continue, X to cancel] : ";
        cin >> choose;

        while ((choose != 'y' && choose != 'Y') && (choose != 'x' && choose != 'X'))
        {
            cout << setw(97) << "Wrong choice! Please choose either Y or X :  ";
            cin >> choose;
        }

        if (choose == 'y' || choose == 'Y')
        {
            StudentLevel();
        }

        else if (choose == 'x' || choose == 'X')
            StudentReportQuery();
        
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

}

void StudentRoom()
{

    system("cls");
    string block, totalStudentBlock;
    char choose;

    cout << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "-------------------------------------------------------------------------      STUDENT HOSTEL MANAGEMENT SYSTEM     --------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    // Get the current time in seconds
    time_t t = time(nullptr);

    // Convert the time value to a tm structure
    tm local_time;
    errno_t result = localtime_s(&local_time, &t);


    string currTime = to_string(local_time.tm_year + 1900) + "-" + to_string(local_time.tm_mon + 1) + "-" + to_string(local_time.tm_mday) + " " +
        to_string(local_time.tm_hour) + ":" + to_string(local_time.tm_min);

    cout << setw(98) << "Date and time now is : " << currTime << endl;
    cout << endl;
    cout << endl;

    cout << setw(112) << "--- Students Information In A Room ---" << endl;
    cout << "\n\n";
    cout << setw(97) << "Enter Room : ";
   cin.ignore(1, '\n');
    getline(cin, roomNo);


    string checkRoom_query = "SELECT * from  room  where roomNo = '" + roomNo + "'";
    const char* cu = checkRoom_query.c_str();
    qstate = mysql_query(conn, cu);

    if (!qstate)
    {
        res = mysql_store_result(conn);
        if (res->row_count == 1)
        {

            string checkRoom_query = "SELECT * from  student  where roomNo = '" + roomNo + "'";
            const char* cu = checkRoom_query.c_str();
            qstate = mysql_query(conn, cu);

            if (!qstate)
            {
                res = mysql_store_result(conn);
                if (res->row_count > 0)
                {
                    cout << "\n";
                    cout << "\t\t" << left << setw(105) << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

                    cout << "\t\t" << left << setw(25) << "   MATRIC NUMBER" << setw(50) << "   STUDENT NAME" << setw(30) << "  EMAIL" << setw(20) << "PHONE NUMBER" << setw(20) << "SEMESTER" << setw(20) << "REGISTER DATE" << endl;
                    cout << "\t\t" << left << setw(105) << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                    int i = 1;
                    while (row = mysql_fetch_row(res))
                    {
                        cout << "\t\t" << left << setw(5) << i << setw(20) << row[0] << setw(50) << row[3] << setw(30) << row[4] << setw(20) << row[5] << setw(20) << row[6] << setw(20) << row[7] << endl;
                        cout << endl;
                        i++;
                    }

                    cout << endl;
                    cout << endl;
                    cout << right;


                    cout << setw(110) << "Press any key go to back to report query ...";

                    _getch();

                    StudentReportQuery();


                }
                else
                {
                    cout << endl;
                    cout << setw(125) << "There is no student in this room. Do you want to continue search? [Y to continue, X to cancel] :";
                    cin >> choose;

                    while ((choose != 'y' && choose != 'Y') && (choose != 'x' && choose != 'X'))
                    {
                        cout << setw(97) << "Wrong choice! Please choose either Y or X :  ";
                        cin >> choose;
                    }

                    if (choose == 'y' || choose == 'Y')
                    {
                        StudentRoom();
                    }

                    else if (choose == 'x' || choose == 'X')
                        StudentReportQuery();
                }
            }
        }
        else
        {
            cout << endl;
            cout << setw(97) << "Room number does not exist!. Do you want to try again? [Y to continue, X to cancel] :";
            cin >> choose;

            while ((choose != 'y' && choose != 'Y') && (choose != 'x' && choose != 'X'))
            {
                cout << setw(97) << "Wrong choice! Please choose either Y or X :  ";
                cin >> choose;
            }

            if (choose == 'y' || choose == 'Y')
            {
                StudentRoom();
            }

            else if (choose == 'x' || choose == 'X')
                StudentReportQuery();
        }

    }
    else
    cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    

}

 
void UpdateStudent()
{
    system("cls");
    char update;
    string  semester, studentEmail, studentPhoneNo, studentPassword;
    char chooseUpdate;

    string reportStatus;

    string search_query = "select matricNo from student where matricNo like '%" + matricNo + "%'";
    const char* u = search_query.c_str();
    qstate = mysql_query(conn, u);

    if (!qstate)
    {
        res = mysql_store_result(conn);
        if (row = mysql_fetch_row(res))
        {
            matricNo = row[0];
        }
    }
    cout << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "-------------------------------------------------------------------------      STUDENT HOSTEL MANAGEMENT SYSTEM     --------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    // Get the current time in seconds
    time_t t = time(nullptr);

    // Convert the time value to a tm structure
    tm local_time;
    errno_t result = localtime_s(&local_time, &t);


    string currTime = to_string(local_time.tm_year + 1900) + "-" + to_string(local_time.tm_mon + 1) + "-" + to_string(local_time.tm_mday) + " " +
        to_string(local_time.tm_hour) + ":" + to_string(local_time.tm_min);

    cout << setw(98) << "Date and time now is : " << currTime << endl;
    cout << endl;
    cout << endl;

    cout << setw(105) << "----Update Student Details----" << endl;
    cout << "\n";
    cout << setw(105) << "Do you want to update student details ? [Y - yes /N - no] : ";
    cin >> update;


    while ((update != 'y' && update != 'Y') && (update != 'n' && update != 'N'))
    {
        cout << setw(105) << "Wrong choice! Please choose either Y or N :  ";
        cin >> update;
    }

    
    do
    {
        system("cls");
        cout << endl;
        cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << endl;
        cout << "-------------------------------------------------------------------------      STUDENT HOSTEL MANAGEMENT SYSTEM     --------------------------------------------------------------------------" << endl;
        cout << endl;
        cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << endl;
        
        cout << setw(98) << "Date and time now is : " << currTime << endl;
        cout << endl;
        cout << endl;

        if (update == 'y' || update == 'Y')
        {     

            //cout << "Enter Matric No : ";
            //cin >> matricNo;

            do {
                string search_report = "select  roomNo, facultyCode, studentPassword, studentName, studentEmail, studentPhoneNo, semester, dateRegister from student where matricNo = '" + matricNo + "'";
                const char* q = search_report.c_str();
                qstate = mysql_query(conn, q);
                res = mysql_store_result(conn);

                if (res->row_count == 1)
                {
                    while (row = mysql_fetch_row(res)) // looping to retrieve data
                    {

                        cout << "\t\t\t\t\t\t\t\t=====================================================================" << endl;
                        cout << "\n";
                        cout << setw(112) << ">>>       Student Details     <<<" << endl<<endl;

                        cout << setw(93) << " Matric No : " << matricNo << "  (Uneditable) " << endl;
                        cout << "\n";
                        cout << setw(97) << " Date Register : " << row[7] << endl;
                        cout << "\n";
                        cout << setw(95) << " Faculty Code : " << row[1] << endl;
                        cout << "\n";
                        cout << setw(94) << " Room Number : " << row[0] << endl;
                        cout << "\n";
                        cout << setw(87) << " Name : " << row[3] << endl;
                        cout << "\n";
                        cout << setw(89) << " Email : " << row[3] << endl;
                        cout << "\n";
                        cout << setw(94) << "[1] Semester: " << row[6] << endl;
                        cout << setw(95) << "[2] Password : " << row[2] << endl;
                        cout << setw(98) << "[3] Phone Number: " << row[5] << endl;
                        cout << "\n";
                        cout << "\t\t\t\t\t\t\t\t=====================================================================" << endl;

                    }

                    cout << "\n";
                    cout << "\n";
                    cout << setw(115) << "Choose [1-3] to update, X to cancel : ";
                    cin >> chooseUpdate;
                    cin.ignore(1, '\n');

                    while (chooseUpdate != 'x' && chooseUpdate != 'X' && chooseUpdate != '1'&& chooseUpdate != '2' && chooseUpdate != '3' && chooseUpdate != '4')
                    {
                        cout << setw(117) << "Wrong choice! Please choose either [1-4] or X to cancel :  ";
                        cin >> chooseUpdate;
                    }


                    if (chooseUpdate == 'x' || chooseUpdate == 'X')
                        StudentMenu();

                    else if (chooseUpdate == '1')
                    {
                        cout << "\n";
                        cout << setw(108) << "Insert current semester (X/X) : ";
                        //cin.ignore(1, '\n');
                        getline(cin, semester);
                        string update_product = "update student set semester = '" + semester + "' where matricNo = '" + matricNo + "'";
                        const char* q = update_product.c_str();
                        qstate = mysql_query(conn, q);

                        cout << "\n";
                        cout << setw(108) << "Student Details Updated!"<<endl;
                        //system("pause");
                        cout << setw(110) << "Press any key to continue..." << endl;
                        _getch();
                        UpdateStudent();

                    }

               

                    else if (chooseUpdate == '2')
                    {
                        cout << setw(108) << "Insert new password : ";
                        getline(cin, studentPassword);

                        while ((studentPassword.length() != 8))
                        {

                            cout << endl;
                            cout << setw(115) << "Invalid lenght of password! Please enter 8 character of password : ";
                            cin >> studentPassword;

                        }

                        string update_product = "update student set studentPassword = '" + studentPassword + "' where matricNo = '" + matricNo + "'";
                        const char* q = update_product.c_str();
                        qstate = mysql_query(conn, q);

                        cout << "\n";
                        cout << setw(108) << "Student Details Updated!" << endl;
                        cout << setw(110) << "Press any key to continue..." << endl;
                        _getch();
                        UpdateStudent();
                    }

                    else if (chooseUpdate == '3')
                    {
                        cout << setw(108) << "Insert new phone number : ";
                        getline(cin, studentPhoneNo);

                        while ((studentPhoneNo.length() != 10) && (studentPhoneNo.length() != 11))
                        {

                            cout << endl;
                            cout << setw(115) << "Invalid lenght of Phone Number! Please enter 10-11 character of numbers  : ";
                            cin >> studentPhoneNo;

                        }

                        string update_product = "update student set studentPhoneNo = '" + studentPhoneNo + "' where matricNo = '" + matricNo + "'";
                        const char* q = update_product.c_str();
                        qstate = mysql_query(conn, q);

                        cout << "\n";
                        cout << setw(108) << "Student Details Updated!" << endl;
                        cout << setw(110) << "Press any key to continue..." << endl;
                        _getch();
                        UpdateStudent();
                    }
                    else
                    {
                        cout << setw(110) << "Incorrect input! Please enter [1-3] only" << endl;
                        cout << setw(110) << "Press any key to continue...." << endl;
                        _getch();
                        UpdateStudent();

                    }


                }
                else
                {
                    cout << setw(108) << "invalid matric no " << endl;
                    _getch();
                    UpdateStudent();
                }

            } while (chooseUpdate != 1 && chooseUpdate != 2 && chooseUpdate != 3 && chooseUpdate != 4);
        }
        else
            StudentMenu();
    } while (update != 'y' && update != 'Y' && update != 'N' && update != 'n');
}

void ElectricalAppliance()
{
    system("cls");

    //ostringstream totalPriceTemp;
    string  applianceCode, registerDate;
    //double charge , totalCharges=0.0;

    char choose;


    cout << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "-------------------------------------------------------------------------      STUDENT HOSTEL MANAGEMENT SYSTEM     --------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    // Get the current time in seconds
    time_t t = time(nullptr);

    // Convert the time value to a tm structure
    tm local_time;
    errno_t result = localtime_s(&local_time, &t);


    string currTime = to_string(local_time.tm_year + 1900) + "-" + to_string(local_time.tm_mon + 1) + "-" + to_string(local_time.tm_mday) + " " +
        to_string(local_time.tm_hour) + ":" + to_string(local_time.tm_min);

    cout << setw(98) << "Date and time now is : " << currTime << endl;
    cout << endl;
    cout << endl;


    cout << setw(115) << "--- Electrical Appliance Registration ---" << endl;
            
    string a = "select matricNo from student where matricNo = '" +matricNo+ "'";
    const char* b = a.c_str();
    qstate = mysql_query(conn, b);

    if (!qstate)
    {
        res = mysql_store_result(conn);
        while (row = mysql_fetch_row(res))
        {
            matricNo= row[0];
        }
    }
    else
     cout << setw(105) << "Matric Not Available" << endl;
    
        cout << endl;
        cout << setw(124) << ">>>       List Of Allowed Electrical Appliances       <<<" << endl;
        cout << endl;
        qstate = mysql_query(conn, "select * from electrical_appliance");

            if (!qstate)
            {
                cout << setw(85) << "APPLIANCE CODE" << setw(20) << "APPLIANCE TYPE" << setw(20) << "APPLIANCE CHARGE " << endl;
                cout << setw(126) << "--------------------------------------------------------------" << endl;

                res = mysql_store_result(conn);
                while (row = mysql_fetch_row(res))
                {
                    cout <<  setw(77) << row[0] << setw(24) << row[1] << setw(20) << row[2] << setw(20) << row[3] << endl;

                }
            }

            cout << endl;
            cout << endl;

            cout << setw(107) << "Insert Appliance Code to be registered : ";
            cin>> applianceCode;

            string checkA = "select applianceCode from electrical_appliance where applianceCode = '" +applianceCode+ "'";
            const char* d = checkA.c_str();
            qstate = mysql_query(conn, d);
            if (!qstate)
            {
                res = mysql_store_result(conn);
                if (res->row_count == 1) 
                {

                    time_t t = time(nullptr);
                    tm local_time;
                    errno_t result = localtime_s(&local_time, &t);
                    string currDate = to_string(local_time.tm_year + 1900) + "-" + to_string(local_time.tm_mon + 1) + "-" + to_string(local_time.tm_mday);

                    string insert_Product_query = "insert into appliance_registration (matricNo, applianceCode,  appRegDate) values ('" + matricNo + "','" + applianceCode + "','" + currDate + "')";
                    const char* cu = insert_Product_query.c_str();
                    qstate = mysql_query(conn, cu);
                    cout << endl;
                    cout << setw(112) << "Product successfully inserted! " << endl;

                    if (!qstate)
                    {
                        

                            cout << endl;
                            cout << setw(110) << "Do you want add another product? [Y-yes , N-no] : ";
                            cin >> choose;

                            while ((choose != 'y' && choose != 'Y') && (choose != 'n' && choose != 'N') )
                            {
                                cout << endl;
                                cout << setw(110) << "Wrong choice! Please choose either Y or N :  ";
                                cin >> choose;
                            }

                            while (choose == 'y' || choose == 'Y')
                            {
                                cout << endl;
                                cout << setw(110) << "Insert Appliance Code to be registered : ";
                                cin.ignore(1, '\n');
                                getline(cin, applianceCode);

                                string checkA = "select * from electrical_appliance where applianceCode = '" + applianceCode + "'";
                                const char* d = checkA.c_str();
                                qstate = mysql_query(conn, d);
                                if (!qstate)
                                {
                                    res = mysql_store_result(conn);

                                    while (res->row_count == 0)
                                    {
                                        cout << endl;
                                        cout << setw(118) << "Incorrect Appliance Code! Please re-enter code again : ";
                                        cin >> applianceCode;
                                        string checkA = "select * from electrical_appliance where applianceCode = '" + applianceCode + "'";
                                        const char* d = checkA.c_str();
                                        qstate = mysql_query(conn, d);
                                        res = mysql_store_result(conn);

                                       /* string checkA = "select applianceCharge from electrical_appliance where applianceCode = '" + applianceCode + "'";
                                        const char* d = checkA.c_str();
                                        qstate = mysql_query(conn, d);
                                        res = mysql_store_result(conn);*/
                                    }

                                    if (res->row_count == 1)
                                    {
                                       /* while (row = mysql_fetch_row(res))
                                        {
                                            appCharge = row[0];

                                        }*/
                                       /* charge = stod(appCharge);
                                        totalCharges = totalCharges + charge;*/

                                        string insert_Product_query = "insert into appliance_registration (matricNo, applianceCode,  appRegDate) values ('" + matricNo + "','" + applianceCode + "','" + currDate + "')";
                                        const char* cu = insert_Product_query.c_str();
                                        qstate = mysql_query(conn, cu);

                                        cout << setw(115) << "Product successfully inserted! " << endl;
                                        

                                    }

                                }
                                else
                                    cout << "Query Execution Problem!" << mysql_errno(conn) << endl;

                                cout << endl;
                                cout << setw(115) << "Do you want add another product? [Y-yes , N-no] : ";
                                cin >> choose;

                                while ((choose != 'y' && choose != 'Y') && (choose != 'n' && choose != 'N'))
                                {
                                    cout << setw(105) << "Wrong choice! Please choose either Y or N :  ";
                                    cin >> choose;
                                }

                            }

                            if (choose == 'n' || choose == 'N')
                            {
                                CalculateAppliance();
                            }

                    }
                     else
                     cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
                }
                else
                {
                    cout << setw(115) << "Incorrect Appliance Code! Press any key to try again..." << endl;
                    _getch();
                    ElectricalAppliance();
                }
            }
            else
            cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
            
}

void CalculateAppliance() 
{
    system("cls");
    char choose;
    string appRegId;

    cout << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "-------------------------------------------------------------------------      STUDENT HOSTEL MANAGEMENT SYSTEM     --------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    // Get the current time in seconds
    time_t t = time(nullptr);

    // Convert the time value to a tm structure
    tm local_time;
    errno_t result = localtime_s(&local_time, &t);


    string currTime = to_string(local_time.tm_year + 1900) + "-" + to_string(local_time.tm_mon + 1) + "-" + to_string(local_time.tm_mday) + " " +
        to_string(local_time.tm_hour) + ":" + to_string(local_time.tm_min);

    cout << setw(98) << "Date and time now is : " << currTime << endl;
    cout << endl;
    cout << endl;


    cout << setw(125) << "--- Electrical Appliance Registration Confirmation ---" << endl;
 /*   time_t t = time(nullptr);
    tm local_time;
    errno_t result = localtime_s(&local_time, &t);*/
    string currDate = to_string(local_time.tm_year + 1900) + "-" + to_string(local_time.tm_mon + 1) + "-" + to_string(local_time.tm_mday);
    string checkA = "SELECT appliance_registration.registerId, electrical_appliance.applianceType, electrical_appliance.applianceCharge FROM appliance_registration INNER JOIN electrical_appliance ON appliance_registration.applianceCode=electrical_appliance.applianceCode where matricNo = '" +matricNo+"' and appRegDate = '"+currDate+"'";
    const char* d = checkA.c_str();
    qstate = mysql_query(conn, d);

    if (!qstate)
    {
        cout << endl;
        cout << setw(95) << "APPLIANCE REGISTRATION ID" << setw(20) << "APPLIANCE TYPE" << setw(20) << "APPLIANCE CHARGE " << endl;
        cout << setw(136) << "--------------------------------------------------------------" << endl;

        res = mysql_store_result(conn);
        if (res->row_count > 1)
        {
            while (row = mysql_fetch_row(res))
            {
                cout << setw(87) << row[0] << setw(24) << row[1] << setw(20) << row[2] << endl;

            }
        }

        cout << endl;

        cout << setw(125) << "Do you want to proceed? Press [Y-yes, N-no] , if you want to cancel an item, press X : ";
        cin >> choose;

        while ((choose != 'y' && choose != 'Y') && (choose != 'n' && choose != 'N') && (choose != 'x' && choose != 'X'))
        {
            cout << setw(120) << "Wrong choice! Please choose either Y or N :  ";
            cin >> choose;
        }


        if (choose == 'y' || choose == 'Y')
        {
           ApplianceRegistrationReceipt();

        }

        else if (choose == 'n' || choose == 'N')
        {
            string delete_query = "delete  from appliance_registration where matricNo = '" + matricNo + "' and appRegDate = '" + currDate + "'";
            const char* q = delete_query.c_str();
            qstate = mysql_query(conn, q);
            cout << setw(120) << "Registration Cancelled! Press any key to back to student menu...  ";
            _getch();
            StudentMenu();
        }

        else if (choose == 'x' || choose == 'X')
            CancelAppRegistration();           

    }

    else 
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;

}
      
void CancelAppRegistration()
{
    system("cls");
    char choose;
    string appRegId;

    cout << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "-------------------------------------------------------------------------      STUDENT HOSTEL MANAGEMENT SYSTEM     --------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    // Get the current time in seconds
    time_t t = time(nullptr);

    // Convert the time value to a tm structure
    tm local_time;
    errno_t result = localtime_s(&local_time, &t);


    string currTime = to_string(local_time.tm_year + 1900) + "-" + to_string(local_time.tm_mon + 1) + "-" + to_string(local_time.tm_mday) + " " +
        to_string(local_time.tm_hour) + ":" + to_string(local_time.tm_min);

    cout << setw(98) << "Date and time now is : " << currTime << endl;
    cout << endl;
    cout << endl;


    cout << setw(125) << "--- Electrical Appliance Registration Confirmation ---" << endl;
    /*   time_t t = time(nullptr);
       tm local_time;
       errno_t result = localtime_s(&local_time, &t);*/
    string currDate = to_string(local_time.tm_year + 1900) + "-" + to_string(local_time.tm_mon + 1) + "-" + to_string(local_time.tm_mday);
    string checkf = "SELECT appliance_registration.registerId, electrical_appliance.applianceType, electrical_appliance.applianceCharge FROM appliance_registration INNER JOIN electrical_appliance ON appliance_registration.applianceCode=electrical_appliance.applianceCode where matricNo = '" + matricNo + "' and appRegDate = '" + currDate + "'";
    const char* f = checkf.c_str();
    qstate = mysql_query(conn, f);

    if (!qstate)
    {
        cout << endl;
        cout << setw(95) << "APPLIANCE REGISTRATION ID" << setw(20) << "APPLIANCE TYPE" << setw(20) << "APPLIANCE CHARGE " << endl;
        cout << setw(136) << "--------------------------------------------------------------" << endl;

        res = mysql_store_result(conn);
        if (res->row_count > 0)
        {
            while (row = mysql_fetch_row(res))
            {
                cout << setw(87) << row[0] << setw(24) << row[1] << setw(20) << row[2] << endl;

            }
        }
    }
    
    cout << endl;
    cout << setw(115) << "Enter Appliance Registration Id to cancel : ";
    cin >> appRegId;

    string checkA = "select * from appliance_registration where registerId = '" + appRegId + "'";
    const char* d = checkA.c_str();
    qstate = mysql_query(conn, d);

    if (!qstate)
    {
        res = mysql_store_result(conn);

        if (res->row_count == 1)
        {
            string delete_query = "delete from appliance_registration where registerId = '" + appRegId + "'";
            const char* q = delete_query.c_str();
            qstate = mysql_query(conn, q);

            cout << setw(75) << appRegId << " Registration Cancelled! do you want to continue cancel item?  [Y-yes/N-no]  :";
            cin >> choose;

            while ((choose != 'y' && choose != 'Y') && (choose != 'n' && choose != 'N'))
            {
                cout << setw(120) << "Wrong choice! Please choose either Y or N :  ";
                cin >> choose;
            }


            if (choose == 'y' || choose == 'Y')
            {
                CancelAppRegistration();

            }

            else if (choose == 'n' || choose == 'N')
                ApplianceRegistrationReceipt();
               
        }
        else
        {
            cout << setw(120) << "Incorrect Appliance Registration Id! Do you want to try again?  [Y-yes/N-no] : ";
            cin >> choose;
            while ((choose != 'y' && choose != 'Y') && (choose != 'n' && choose != 'N'))
            {
                cout << setw(120) << "Wrong choice! Please choose either Y or N :  ";
                cin >> choose;
            }


            if (choose == 'y' || choose == 'Y')
            {
                CancelAppRegistration();

            }

            else if (choose == 'n' || choose == 'N')
                StudentMenu();
        }
    }
    else
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
}

void ApplianceRegistrationReceipt()
{
    system("cls");
    char choose;
    string appRegId, totalCharge;

    cout << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "-------------------------------------------------------------------------      STUDENT HOSTEL MANAGEMENT SYSTEM     --------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    // Get the current time in seconds
    time_t t = time(nullptr);

    // Convert the time value to a tm structure
    tm local_time;
    errno_t result = localtime_s(&local_time, &t);


    string currTime = to_string(local_time.tm_year + 1900) + "-" + to_string(local_time.tm_mon + 1) + "-" + to_string(local_time.tm_mday) + " " +
        to_string(local_time.tm_hour) + ":" + to_string(local_time.tm_min);

    cout << setw(98) << "Date and time now is : " << currTime << endl;
    cout << endl;
    cout << endl;


    cout << setw(125) << "--- Electrical Appliance Receipt ---" << endl;
    /*   time_t t = time(nullptr);
       tm local_time;
       errno_t result = localtime_s(&local_time, &t);*/
    string currDate = to_string(local_time.tm_year + 1900) + "-" + to_string(local_time.tm_mon + 1) + "-" + to_string(local_time.tm_mday);
    string checkA = "SELECT appliance_registration.registerId, electrical_appliance.applianceType, electrical_appliance.applianceCharge FROM appliance_registration INNER JOIN electrical_appliance ON appliance_registration.applianceCode=electrical_appliance.applianceCode where matricNo = '" + matricNo + "' and appRegDate = '" + currDate + "'";
    const char* x = checkA.c_str();
    qstate = mysql_query(conn, x);

    if (!qstate)
    {
        cout << endl;
        cout << setw(95) << "APPLIANCE REGISTRATION ID" << setw(20) << "APPLIANCE TYPE" << setw(20) << "APPLIANCE CHARGE " << endl;
        cout << setw(136) << "--------------------------------------------------------------" << endl;

        res = mysql_store_result(conn);
        if (res->row_count > 1)
        {
            while (row = mysql_fetch_row(res))
            {
                cout << setw(87) << row[0] << setw(24) << row[1] << setw(20) << row[2] << endl;

            }
        }
    }

    string totalC_query = "select sum(applianceCharge) as totalCharge from appliance_registration INNER JOIN electrical_appliance  ON appliance_registration.applianceCode=electrical_appliance.applianceCode where matricNo = '" + matricNo + "' and appRegDate = '" + currDate + "'";
    const char* d = checkA.c_str();
    const char* cuC= totalC_query.c_str();
    qstate = mysql_query(conn, cuC);

    if (!qstate)
    {
        res = mysql_store_result(conn);
        while (row = mysql_fetch_row(res))
        {
            totalCharge = row[0];
        }
        cout << endl;
        cout << setw(125) << "Total Charge = RM " << totalCharge;
        cout << setw(135) << "Press any key to go back to student menu...";
        _getch();
        StudentMenu();

    }
    else
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;

}
void SendReport ()
{
    system("cls");
    string reportId, itemId, reportDate, reportStatus, description, block;

    cout << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "-------------------------------------------------------------------------      STUDENT HOSTEL MANAGEMENT SYSTEM     --------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    // Get the current time in seconds
    time_t t = time(nullptr);

    // Convert the time value to a tm structure
    tm local_time;
    errno_t result = localtime_s(&local_time, &t);

    string currTime = to_string(local_time.tm_year + 1900) + "-" + to_string(local_time.tm_mon + 1) + "-" + to_string(local_time.tm_mday) + " " +
        to_string(local_time.tm_hour) + ":" + to_string(local_time.tm_min);

    cout << setw(98) << "Date and time now is : " << currTime << endl;
    cout << endl;
    cout << endl;

    cout << setw(109) << "--- Send Room Item Report--" << endl;
    string a = "select roomNo from student where matricNo = '" + matricNo + "'";
    const char* b = a.c_str();
    qstate = mysql_query(conn, b);
    
    if (!qstate)
    {
        res=mysql_store_result(conn);
        while (row = mysql_fetch_row(res))
        {
            roomNo = row[0];
        }
        
    }
    else
        cout << setw(109) << "Room Not Available" <<endl;

    string checkRoom_query = "select * from room_item where roomNo = '" + roomNo + "'";
    const char* cu = checkRoom_query.c_str();
    qstate = mysql_query(conn, cu);

    if (!qstate)
    {
        res = mysql_store_result(conn);
        if (res->row_count > 1)
        {
            cout << endl;
            cout <<"\t\t\t\t\t\t\t\t\t\t  ============================" << endl;
            cout << setw(94) << "Item Id" << setw(13) << "Item Type" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t  ===========================" << endl;
            while (row = mysql_fetch_row(res))
            {
                cout << endl;
                cout << setw(93) << row[0] << setw(13) << row[2] << endl;
                
            }

            cout << endl;

            string adminId;
            string status = "New!";

            string checkRoom_query = "select block from room where roomNo = '" + roomNo + "'";
            const char* cuB = checkRoom_query.c_str();
            qstate = mysql_query(conn, cuB);

            if (!qstate)
            {
                res = mysql_store_result(conn);
                if (res->row_count == 1)
                {
                    while (row = mysql_fetch_row(res))
                    {
                        block = row[0];
                    }
                }
            }

            if (block == "A" )
                adminId = "adminA1";
            else if (block == "B")
                adminId = "adminB1";

            cout << setw(107) << "Enter Item Id to report : ";
            cin >> itemId;
            /*cin.ignore(256, '\n');
            getline(cin, itemId);*/

            string checkRoomT_query = "select itemId from room_item where itemId = '" + itemId + "' and roomNo = '" + roomNo + "'";
            const char* cuT = checkRoomT_query.c_str();
            qstate = mysql_query(conn, cuT);

            if (!qstate)
            {
                res = mysql_store_result(conn);
                if (res->row_count == 1)
                {
                    time_t t = time(nullptr);
                    tm local_time;
                    errno_t result = localtime_s(&local_time, &t);
                    string currDate = to_string(local_time.tm_year + 1900) + "-" + to_string(local_time.tm_mon + 1) + "-" + to_string(local_time.tm_mday);

                    cout << setw(105) << "Enter Description: ";
                    cin.ignore(1, '\n');
                    //cin >> description;
                    getline(cin, description);

                    string studentReport_query = "insert into item_report (roomNo, itemId,admin_id, reportDate, description, status) values ('" + roomNo + "', '" + itemId + "','" + adminId + "','" + currDate + "','" + description + "','" + status + "')";
                   // string studentReport_query = "insert into item_report (roomNo, itemId, reportDate, description, status) values ('" + roomNo + "', '" + itemId + "', '" + currDate + "','" + description + "','" + status + "')";

                    const char* q = studentReport_query.c_str();
                    qstate = mysql_query(conn, q);

                   // cout<<roomNo<<endl;
                    //cout<< itemId << endl;
                    //cout << qstate << endl;

                    if (!qstate)
                    {
                        cout << endl;
                        cout << setw(120) << "Your report has been sent. Press any key to continue...";
                        _getch();
                        system("cls");
                        StudentMenu();
                    }
                    else
                    {
                        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
                    }
                }
                else
                {
                    cout << setw(127) << "Incorrect Item Id! Press any key to try again..." << endl;
                    _getch();
                    SendReport();
                }
            }
        }
        else
        {
            cout << setw(127) << "Wrong room number. Press any key to Try Again...";
            _getch();
            system("cls");
            SendReport();
        }
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
        
    }
}

void UpdateRoomItem() {
    system("cls");

    string itemId, quantity;
    char chooseUpdate;

    cout << endl;

    cout << endl;

    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "---------------------------------------------------------------      STUDENT HOSTEL MANAGEMENT SYSTEM     ------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
   
    // Get the current time in seconds
    time_t t = time(nullptr);

    // Convert the time value to a tm structure
    tm local_time;
    errno_t result = localtime_s(&local_time, &t);

    string currTime = to_string(local_time.tm_year + 1900) + "-" + to_string(local_time.tm_mon + 1) + "-" + to_string(local_time.tm_mday) + " " +
        to_string(local_time.tm_hour) + ":" + to_string(local_time.tm_min);

    cout << setw(98) << "Date and time now is : " << currTime << endl;
    cout << endl;
    cout << endl;

    cout << setw(105) << "--- List of Room Item  --" << endl;
    string a = "select roomNo from student where matricNo = '" + matricNo + "'";
    const char* b = a.c_str();
    qstate = mysql_query(conn, b);

    if (!qstate)
    {
        res = mysql_store_result(conn);
        while (row = mysql_fetch_row(res))
        {
            roomNo = row[0];
        }
    }
    else
        cout << setw(105) << "Room Not Available" << endl;

    string checkUser_query = "select itemId, itemType, itemQuantity from room_item where roomNo = '" + roomNo + "'";
    const char* cu = checkUser_query.c_str();
    qstate = mysql_query(conn, cu);

    if (!qstate)
    {
        res = mysql_store_result(conn);
        if (res->row_count > 1)
        {
            cout << endl;
            cout << "\t\t" << setw(68) << "Item Id" << setw(13) << "Item Type" << setw(13) << "Quantity" << endl;

            while (row = mysql_fetch_row(res))
            {
                cout << "\t\t" << setw(66) << row[0] << setw(13) << row[1] << setw(13) << row[2] << endl;
            }
        }
        else
        {
            cout << setw(115) << "Query Execution Problem" << mysql_errno << endl;
        }

        cout << endl;
        cout << setw(117) << "Do you want to update quantity item? Press [Y-yes, N-No] : ";
        //cin.ignore(1, '\n');
        cin >> chooseUpdate;

        while ((chooseUpdate != 'y' && chooseUpdate != 'Y') && (chooseUpdate != 'n' && chooseUpdate != 'N'))
        {
            cout << setw(115) << "Wrong choice! Please choose either Y or N :  ";
            cin >> chooseUpdate;
        }

        if (chooseUpdate == 'n' || chooseUpdate == 'N') 
            StudentMenu();
        

        else if (chooseUpdate == 'y' || chooseUpdate == 'Y') 
        {
            cout << setw(115) << "Enter item id : ";
            cin.ignore(1, '\n');
            getline(cin, itemId);

            string check_inv = "select * from room_item where itemId = '" + itemId + "' and roomNo='" + roomNo + "'";
            const char* q = check_inv.c_str();
            qstate = mysql_query(conn, q);
            if (!qstate)
            {
                res = mysql_store_result(conn);
                if (res->row_count == 1)
                {
                    cout << setw(115) << "Enter current quantity : ";
                    getline(cin, quantity);

                    string update_quantity = "update room_item set itemQuantity = '" + quantity + "' where roomNo = '" + roomNo + "' and itemId = '" + itemId + "'";
                    const char* q = update_quantity.c_str();
                    qstate = mysql_query(conn, q);

                    cout << setw(115) << "Quantity item Updated! Press Any Key to continue..." << endl;
                    _getch();
                    UpdateRoomItem();
                }
                else
                    cout << setw(115) << "Incorrect item id. Please enter Y to continue, press X to cancel";
                    cin >> chooseUpdate;

                    while ((chooseUpdate != 'y' && chooseUpdate != 'Y') && (chooseUpdate != 'x' && chooseUpdate != 'X'))
                    {
                        cout << setw(115) << "Wrong choice! Please choose either Y or X :  ";
                        cin >> chooseUpdate;
                    }

                    if (chooseUpdate == 'y' || chooseUpdate == 'Y')
                        UpdateRoomItem();

                    else if (chooseUpdate == 'x' || chooseUpdate == 'X')
                        StudentMenu();
            }
            else
                cout << setw(115) << "Query Execution Problem" << mysql_errno << endl;

        }
       
    }
       else
        cout << setw(115) << "Query Execution Problem" << mysql_errno << endl;
    
}


   

      




