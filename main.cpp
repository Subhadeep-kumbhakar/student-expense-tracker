```cpp
#include <iostream>
#include <windows.h>
#include "ExpenseManager.h"

using namespace std;

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int main() {

    ExpenseManager manager;

    manager.loadFromFile();

    int choice;

    while (true) {

        setColor(11);

        cout << "\n====================================\n";
        cout << "     STUDENT EXPENSE TRACKER\n";
        cout << "====================================\n";

        setColor(14);

        cout << "1. Add Expense\n";
        cout << "2. View Expenses\n";
        cout << "3. Show Total Expense\n";
        cout << "4. Delete Expense\n";
        cout << "5. Exit\n";

        setColor(7);

        cout << "Choose option: ";

        cin >> choice;

        cin.ignore();

        switch (choice) {

            case 1: {

                double amount;
                string category;
                string note;

                setColor(11);

                cout << "Enter amount: ";
                cin >> amount;

                cin.ignore();

                cout << "Enter category: ";
                getline(cin, category);

                cout << "Enter note: ";
                getline(cin, note);

                Expense expense(amount, category, note);

                manager.addExpense(expense);

                manager.saveToFile();

                setColor(10);

                cout << "Expense added successfully!\n";

                setColor(7);

                break;
            }

            case 2:

                setColor(11);

                manager.viewExpenses();

                setColor(7);

                break;

            case 3:

                setColor(10);

                cout << "Total Expense = ₹"
                     << manager.getTotalExpense()
                     << endl;

                setColor(7);

                break;

            case 4: {

                int expenseNumber;

                manager.viewExpenses();

                setColor(14);

                cout << "Enter expense number to delete: ";
                cin >> expenseNumber;

                manager.deleteExpense(expenseNumber - 1);

                manager.saveToFile();

                setColor(7);

                break;
            }

            case 5:

                setColor(10);

                cout << "Exiting...\n";

                setColor(7);

                return 0;

            default:

                setColor(12);

                cout << "Invalid choice!\n";

                setColor(7);
        }
    }

    return 0;
}
```
