#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip> // Include this header for std::put_time

using namespace std; // This allows us to use std classes and functions without the std:: prefix.

int main() {
    // Get current time as time_point
    auto now = chrono::system_clock::now();
    
    // Convert time_point to time_t for easy conversion to local time
    time_t now_time_t = chrono::system_clock::to_time_t(now);
    
    // Convert to local time
    tm* local_time = localtime(&now_time_t);
    
    // Print the current date and time
    cout << "Current date and time: " 
         << put_time(local_time, "%Y-%m-%d %H:%M:%S") << endl;

    return 0;
}
