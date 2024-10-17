#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <iomanip>
void clearScreen() {
    system("cls");
}

using namespace std;

struct account {
    int id;
    string name;
    string password;
    double balance;
};

// Function prototypes
void writeCSV(const string& filename, const account& acc);
string login(const string& filename, int id);
string getInput(const string& data, const string& datatype, int length, int choice);
long long getUnixTimestamp();
void Session_logger(const string& filename, const string& changed_aspect, const account& acc, long long session_id);

int main() {
    struct account user1;
    int input;
    long long session_id = getUnixTimestamp();

    while (true) {
        clearScreen();
    cout << endl; // Add space before menu
    cout << "============================" << endl;
    cout << "        Bank Menu           " << endl;
    cout << "============================" << endl;
    cout << "1. Create account" << endl;
    cout << "2. Log in to account" << endl;
    cout << "3. Exit" << endl;  // Added option to exit
    cout << "============================" << endl;
    cout << "Please enter your choice: ";
        cin >> input;
        cin.ignore();  // To avoid any leftover input in the buffer

        switch (input) {
            case 1:
                // Collect user inputs
                user1.id = stoi(getInput("ID", "numbers", 10, 1));
                user1.password = getInput("Password", "characters", 8, 1);
                user1.balance = stod(getInput("Balance", "number", 3, 0));  // Use stod for double
                user1.name = getInput("Name", "characters", 3, 0);

                writeCSV("database.csv", user1);
                cout << "account has been created " << endl;
                Session_logger("sessions.csv","account_created",user1 ,session_id);
                break;

            case 2: {
                int choice2;
                int id = stoi(getInput("id","number",5,0));
                string password = getInput("Password", "characters", 8, 1);
                ;

                
                string token = login("database.csv", id);
                if (password == token)
                {
                    //inner switch

                } else {
                    clearScreen();
                    cout << "wrong password \n\n\n";
                }
                

                

                break;
            }

            case 3:
                cout << "Exiting the program." << endl;
                return 0;  // Exit the program

            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
    }

    return 0;
}
/*
data = name of value you want to take from user ex- password , id , name;
datatype = type of value you want ask user to give ex-number , characters;
length = lenth allowed
choice if a definite length input is needed then 1
if checking of lenth is required then 0


*/
string getInput(const string& data, const string& datatype, int length, int choice) {
    string userInput;

    if (choice) {
        // Loop until valid input length is matched
        while (true) {
            cout << "Enter a " << data << " (exactly " << length << " " << datatype << "): ";
            getline(cin, userInput);

            if (userInput.length() == length) {
                return userInput;  // Valid input
            } else {
                cout << "Input is invalid. Please try again." << endl;
            }
        }
    } else {
        // For inputs without strict length requirement
        while (true) {
            cout << "Enter " << data << ": ";
            getline(cin, userInput);

            if (!userInput.empty()) {
                return userInput;  // Valid input
            } else {
                cout << "Input is invalid. Please try again." << endl;
            }
        }
    }
}

void writeCSV(const string& filename, const account& acc) {
    ofstream file(filename, ios::app);

    // Check if file is open
    if (file.is_open()) {
        // Write account details as a new row in the CSV
        file << acc.id << "," << acc.password << "," << acc.name << "," << acc.balance << endl;
        file.close();
        cout << "Record added successfully." << endl;
    } else {
        cout << "Unable to open file for writing." << endl;
    }
}

// Function to return password if value is found
string login(const string& filename, int id) {
    ifstream file(filename);  // Open the CSV file
    string line;

    // Check if the file is open
    if (!file.is_open()) {
        return "Unable to open file";  // Error message if the file can't be opened
    }

    // Read file line by line
    while (getline(file, line)) {
        int firstColumn;
        string password, name;
        double balance;
        stringstream s(line);  // Create stringstream from the line

        // Get the first column value (ID)
        s >> firstColumn; // Use >> to read an integer
        s.ignore(); // Ignore the comma
        getline(s, password, ','); // Get the second column (password)
        getline(s, name, ','); // Get the third column (name)
        s >> balance; // Get the fourth column (balance)

        // Check if the first column matches the search value (ID)
        if (firstColumn == id) {
            return password;  // Return the password
        }
    }

    // If value not found
    return "User doesn't exist";  // Return a message if user is not found
}

// Function to get current date and time as a string
string getCurrentDateTime() {
    // Get current time as time_point
    auto now = chrono::system_clock::now();
    
    // Convert time_point to time_t for easy conversion to local time
    time_t now_time_t = chrono::system_clock::to_time_t(now);
    
    // Convert to local time
    tm* local_time = localtime(&now_time_t);
    
    // Create a string stream to format the time
    ostringstream oss;
    oss << put_time(local_time, "%Y-%m-%d %H:%M:%S");
    
    // Return the formatted string
    return oss.str();
}
  //get unix timestamp as session id
long long getUnixTimestamp() {
    // Get current time as time_point
    auto now = chrono::system_clock::now();
    
    // Convert time_point to time_t to get the number of seconds since epoch
    time_t unix_timestamp = chrono::system_clock::to_time_t(now);
    
    return static_cast<long long>(unix_timestamp);
}

// Function to log session details

void Session_logger(const string& filename, const string& changed_aspect, const account& acc, long long session_id )
 {
    ofstream file(filename, ios::app); // Open file in append mode
    string dateTime = getCurrentDateTime();
    


    // Check if file is open
    if (file.is_open()) {
        // Check the type of action using if-else
        if (changed_aspect == "account_created") {
            // Write account details as a new row in the CSV
            file << session_id << ", " << dateTime << ", " << acc.id << ", " << changed_aspect << endl;
            cout << "Record added successfully." << endl;
        } else {
            cout << "No valid action for logging." << endl;
        }

        file.close();
    } else {
        cout << "Unable to open file for writing." << endl;
    }
}
