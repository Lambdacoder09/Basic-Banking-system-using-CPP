

# **Basic Banking System Using C++**

## **Project Overview**
This is a simple banking management system developed using C++ to demonstrate various programming concepts such as file handling, user input validation, and logging. The system supports account creation, login functionality, and transaction management, and maintains logs for different operations.

## **Features**
1. **Create New Account**
   - Allows the user to create a new account with a unique ID, password, name, and initial balance.
   
2. **Log In**
   - Users can log into their accounts using their ID and password.
   
3. **View Account Details**
   - Displays the account balance and user information.

4. **Deposit and Withdraw**
   - Users can deposit and withdraw money from their accounts.

5. **Transaction Logs**
   - Keeps track of every session and transaction in a separate log file (`sessions.csv`), along with the timestamp and session ID.

## **File Structure**
- `main.cpp` - Main source code file containing the entire program logic.
- `database.csv` - Stores user account information such as ID, name, password, and balance.
- `sessions.csv` - Stores session and activity logs such as account creation, deposits, and withdrawals.

## **How to Run the Project**
1. **Clone the Repository:**

   ```bash
   git clone <repository-url>
   cd Basic-Banking-system-using-CPP
   ```

2. **Compile the Program:**

   Open a terminal or command prompt and navigate to the project directory:

   ```bash
   g++ main.cpp -o BankingSystem
   ```

3. **Run the Program:**

   ```bash
   ./BankingSystem
   ```

   **For Windows users:**

   ```bash
   BankingSystem.exe
   ```

## **How to Use the Program**
1. **Creating a New Account:**
   - Choose the option `1` from the menu.
   - Enter the required details: ID, Name, Password, and Initial Balance.
   - The details will be saved in `database.csv`, and a log will be created in `sessions.csv`.

2. **Logging into an Existing Account:**
   - Choose the option `2`.
   - Enter your account ID and password.
   - If the details match, you will be logged in and can perform transactions or view account details.

3. **Exiting the Program:**
   - Choose option `3` to safely exit.

## **Dependencies**
- C++ Compiler (e.g., `g++`).
- Make sure to have the necessary permissions to read/write files in the project directory.

## **Future Enhancements**
1. **Password Encryption:**
   - Add support for encrypting passwords for better security.

2. **Transfer Between Accounts:**
   - Implement a transfer feature to allow users to send money to other accounts.

3. **Graphical User Interface (GUI):**
   - Create a GUI version of the application using libraries such as Qt.

4. **Improved Logging:**
   - Add more detailed logging for transactions like deposits, withdrawals, and failed login attempts.

## **Contributing**
If you wish to contribute to the project, feel free to fork the repository, create a new branch, and submit a pull request with your changes.

## **License**
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## **Acknowledgments**
- Inspiration from various basic C++ projects.
- Guidance and support from mentors and online communities.


