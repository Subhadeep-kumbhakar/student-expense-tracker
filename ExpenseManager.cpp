
#include "ExpenseManager.h"

#include <iostream>
#include <fstream>

using namespace std;

void ExpenseManager::addExpense(Expense expense) {

    expenses.push_back(expense);
}

void ExpenseManager::viewExpenses() {

    if (expenses.empty()) {

        cout << "\nNo expenses found.\n";
        return;
    }

    cout << "\n===== All Expenses =====\n";

    for (int i = 0; i < expenses.size(); i++) {

        cout << "\nExpense " << i + 1 << endl;

        cout << "Amount: " << expenses[i].getAmount() << endl;

        cout << "Category: " << expenses[i].getCategory() << endl;

        cout << "Note: " << expenses[i].getNote() << endl;
    }
}

double ExpenseManager::getTotalExpense() {

    double total = 0;

    for (Expense expense : expenses) {

        total += expense.getAmount();
    }

    return total;
}

void ExpenseManager::deleteExpense(int index) {

    if (index < 0 || index >= expenses.size()) {

        cout << "\nInvalid expense number.\n";
        return;
    }

    expenses.erase(expenses.begin() + index);

    cout << "\nExpense deleted successfully.\n";
}

void ExpenseManager::saveToFile() {

    ofstream file("expenses.txt");

    for (Expense expense : expenses) {

        file << expense.getAmount() << endl;
        file << expense.getCategory() << endl;
        file << expense.getNote() << endl;
    }

    file.close();
}

void ExpenseManager::loadFromFile() {

    ifstream file("expenses.txt");

    if (!file) {

        return;
    }

    double amount;
    string category;
    string note;

    while (file >> amount) {

        file.ignore();

        getline(file, category);

        getline(file, note);

        Expense expense(amount, category, note);

        expenses.push_back(expense);
    }

    file.close();
}

