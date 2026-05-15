#include <iostream>
#include <string>
#include <iomanip>
#include "ExpenseManager.h"

using namespace std;

void printMenu() {
    cout << "\n=============================\n";
    cout << "   STUDENT EXPENSE TRACKER   \n";
    cout << "=============================\n";
    cout << "1. Add Expense\n";
    cout << "2. View All Expenses\n";
    cout << "3. View Total Expense\n";
    cout << "4. Delete Expense\n";
    cout << "5. Save Expenses\n";
    cout << "6. Load Expenses\n";
    cout << "0. Exit\n";
    cout << "-----------------------------\n";
    cout << "Enter your choice: ";
}

int main() {
    ExpenseManager manager;

    // Auto-load on startup
    manager.loadFromFile();

    int choice;

    do {
        printMenu();
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        cin.ignore(); // flush newline

        switch (choice) {

            case 1: {
                double amount;
                string category, note;

                cout << "Enter amount (Rs.): ";
                cin >> amount;
                cin.ignore();

                if (amount <= 0) {
                    cout << "Amount must be greater than 0.\n";
                    break;
                }

                cout << "Enter category (e.g. Food, Transport, Books): ";
                getline(cin, category);

                cout << "Enter note (optional, press Enter to skip): ";
                getline(cin, note);

                manager.addExpense(Expense(amount, category, note));
                break;
            }

            case 2:
                manager.viewExpenses();
                break;

            case 3:
                cout << "\nTotal Expense: Rs. "
                     << fixed << setprecision(2)
                     << manager.getTotalExpense() << "\n";
                break;

            case 4: {
                manager.viewExpenses();
                int idx;
                cout << "Enter expense number to delete: ";
                cin >> idx;
                cin.ignore();
                manager.deleteExpense(idx);
                break;
            }

            case 5:
                manager.saveToFile();
                break;

            case 6:
                manager.loadFromFile();
                break;

            case 0:
                cout << "Saving and exiting... Goodbye!\n";
                manager.saveToFile();
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}