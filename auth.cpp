#include"auth.h"

bool Authentication::admin_authentication(const string& adminUser, const string& adminPass){


     return adminUser == "admin" && adminPass == "admin123";
}
bool Authentication::user_authentication(const string& inputUser, const string& inputPass){
     ifstream infile("users.txt");
        if (!infile)
        {return false;}

        string u, p;
        while (infile >> u >> p) {
            if (u == inputUser && p == inputPass)
                {return true;}
        }
        return false;
}

void Authentication::signup() {
    string newUser, newPass;
    bool exists = false;

    do {
        exists = false;
        cout << "\t\t\tEnter new username: ";
        cin >> newUser;

        ifstream infile("users.txt");
        string u, p;

        // Check if username already exists
        while (infile >> u >> p) {
            if (u == newUser) {
                cout << "\t\t\tUsername already Taken. Try another username.\n";
                exists = true;
                break;
            }
        }

    } while (exists); // Repeat if username exists

    cout << "\t\t\tEnter new password: ";
    cin >> newPass;

    // Save the new username and password
    ofstream outfile("users.txt", ios::app);
    if (outfile) {
        outfile << newUser << " " << newPass << endl;
        cout << "\t\t\tUser created successfully.\n";
    } else {
        cout << "\t\t\tError saving user.\n";
    }
}



//admin login with hidden password
bool Authentication::adminLogin() {
    string user, pass;
    cout << "\t\t\tAdmin Username: ";
    cin >> user;
    cout << "\t\t\tAdmin Password: ";
    pass = getHiddenPassword();

    if (admin_authentication(user, pass)) {
        return true;  // admin login success
    } else {
        return false; // failed
    }
}




//user login with hidden password
bool Authentication::userLogin() {
    string user, pass;
    cout << "\t\t\tUsername: ";
    cin >> user;
    cout << "\t\t\tPassword: ";
    pass = getHiddenPassword(); // hides password input

    if (user_authentication(user, pass)) {
        return true;  // login success
    } else {
        return false; // login failed
    }
}


string Authentication::getHiddenPassword() {
    string password;
    char ch;

    while (true) {
        ch = _getch(); // getch() for older compilers

        if (ch == 13) break; // Enter key ascii code
        else if (ch == 8) { // Backspace ascii code
            if (!password.empty()) {
                cout << "\b \b"; // Erase character from screen
                password.pop_back();
            }
        } else {
            password += ch;
            cout << '*'; // Mask character
        }
    }
    cout << endl;
    return password;
}

