#include "ExpenseManager.h"
#include <iostream>

using namespace std;

void ExpenseManager::addExpense(Expense expense) {
    expenses.push_back(expense);
}

void ExpenseManager::viewExpenses() {

    if (expenses.empty()) {
        cout << "No expenses found." << endl;
        return;
    }

    for (int i = 0; i < expenses.size(); i++) {
        cout << i + 1 << ". ";
        expenses[i].display();
    }
}

double ExpenseManager::getTotalExpense() {

    double total = 0;

    for (Expense expense : expenses) {
        total += expense.getAmount();
    }

    return total;
}
