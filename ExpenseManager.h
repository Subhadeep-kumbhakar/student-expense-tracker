#ifndef EXPENSEMANAGER_H
#define EXPENSEMANAGER_H

#include "Expense.h"
#include <vector>

class ExpenseManager {
private:
    vector<Expense> expenses;

public:
    void addExpense(Expense expense);

    void viewExpenses();

    double getTotalExpense();
};

#endif