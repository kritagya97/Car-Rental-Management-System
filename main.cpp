#include "main.h"
int main() {
    int choice, ch;
    char decision;
    Authentication authenticate;
    Decorate d;
    Cases opcase;

    while (true) {
        system("cls");
        d.heading_layout();
        d.options();

        cout << "\t\t\tEnter your choice: ";
        cin >> choice;

        if (choice == 1) {
            system("cls");
            d.admin_layout();

            if (authenticate.adminLogin() == true) {
                do {
                    system("cls");
                    d.admin_account_layout();
                    d.admin_operation();

                    cout << "\n\t\t\tChoose: ";
                    cin >> ch;

                    if (ch == 1) {
                        authenticate.signup(); // create employee
                    } else if (ch != 99) {
                        opcase.switch_cases(ch);
                    }

                    if (ch != 99) {
                        cout << "\n\t\t\tPress any key to continue...";
                        getch();
                    }

                } while (ch != 99);
            } else {
                cout << "\t\t\tIncorrect username or password.\n";
                cout << "\t\t\tPress any key to return to main menu...";
                getch();
            }
        }

        else if (choice == 2) {
            system("cls");
            d.emp_layout();

            if (authenticate.userLogin() == true) {
                do {
                    system("cls");
                    d.emp_account_layout();
                    d.employee_operation();

                    cout << "\n\t\t\tChoose: ";
                    cin >> ch;

                    if (ch != 99) {
                        opcase.emp_cases(ch);
                        cout << "\n\t\t\tPress any key to continue...";
                        getch();
                    }

                } while (ch != 99);
            } else {
                cout << "\t\t\tIncorrect username or password.\n";
                cout << "\t\t\tPress any key to return to main menu...";
                getch();
            }
        }

        else if (choice == 99) {
            cout << "\t\t\tAre you sure you want to exit [Y/N]? ";
            cin >> decision;
            if (decision == 'y' || decision == 'Y') {
                cout << "\n\t\t\tThank you for using CRMS!\n";
                getch();
                break;  // Exit main loop
            }
        }

        else {
            d.line();
            cout << "\t\t\tEnter a valid choice.\n";
            cout << "\t\t\tPress any key to try again...";
            getch();
        }
    }

    return 0;
}
