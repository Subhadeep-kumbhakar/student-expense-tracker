#include <iostream>
#include "ExpenseManager.h"

using namespace std;

int main() {

    ExpenseManager manager;

    int choice;

    while (true) {

        cout << "\n===== Student Expense Tracker =====\n";
        cout << "1. Add Expense\n";
        cout << "2. View Expenses\n";
        cout << "3. Show Total Expense\n";
        cout << "4. Exit\n";

        cout << "Choose option: ";
        cin >> choice;

        cin.ignore();

        switch (choice) {

            case 1: {

                double amount;
                string category;
                string note;

                cout << "Enter amount: ";
                cin >> amount;

                cin.ignore();

                cout << "Enter category: ";
                getline(cin, category);

                cout << "Enter note: ";
                getline(cin, note);

                Expense expense(amount, category, note);

                manager.addExpense(expense);

                cout << "Expense added successfully!\n";

                break;
            }

            case 2:
                manager.viewExpenses();
                break;

            case 3:
                cout << "Total Expense = ₹"
                     << manager.getTotalExpense()
                     << endl;
                break;

            case 4:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    }

    return 0;
}