
#include <iostream>

#include "ExpenseManager.h"

using namespace std;

int main() {

    ExpenseManager manager;

    manager.loadFromFile();

    int choice;

    while (true) {

        cout << "\n===== Student Expense Tracker =====\n";

        cout << "1. Add Expense\n";
        cout << "2. View Expenses\n";
        cout << "3. Show Total Expense\n";
        cout << "4. Delete Expense\n";
        cout << "5. Exit\n";

        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {

            double amount;
            string category;
            string note;

            cout << "\nEnter amount: ";
            cin >> amount;

            cin.ignore();

            cout << "Enter category: ";
            getline(cin, category);

            cout << "Enter note: ";
            getline(cin, note);

            Expense expense(amount, category, note);

            manager.addExpense(expense);

            manager.saveToFile();

            cout << "\nExpense added successfully.\n";
        }

        else if (choice == 2) {

            manager.viewExpenses();
        }

        else if (choice == 3) {

            cout << "\nTotal Expense: "
                 << manager.getTotalExpense()
                 << endl;
        }

        else if (choice == 4) {

            int number;

            cout << "\nEnter expense number to delete: ";
            cin >> number;

            manager.deleteExpense(number - 1);

            manager.saveToFile();
        }

        else if (choice == 5) {

            cout << "\nExiting program...\n";

            break;
        }

        else {

            cout << "\nInvalid choice.\n";
        }
    }

    return 0;
}

