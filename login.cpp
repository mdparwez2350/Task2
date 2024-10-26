#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void registerUser() {
    string username, password;

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    // Create a file with the username
    ofstream userFile(username + ".txt");
    if (userFile.is_open()) {
        userFile << "Username: " << username << endl;
        userFile << "Password: " << password << endl;
        userFile.close();
        cout << "Registration successful! User file created." << endl;
    } else {
        cout << "Error creating user file." << endl;
    }
}

bool loginUser() {
    string username, password, fileUsername, filePassword;

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    // Open the file corresponding to the username
    ifstream userFile(username + ".txt");
    if (userFile.is_open()) {
        getline(userFile, fileUsername);
        getline(userFile, filePassword);
        userFile.close();

        // Check if the entered password matches the stored password
        if (filePassword == "Password: " + password) {
            cout << "Login successful!" << endl;
            return true;
        } else {
            cout << "Invalid username or password." << endl;
            return false;
        }
    } else {
        cout << "User does not exist." << endl;
        return false;
    }
}

int main() {
    int choice;

    while (true) {
        cout << "\n1. Register\n2. Login\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
