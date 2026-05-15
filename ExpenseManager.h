
#ifndef EXPENSEMANAGER_H
#define EXPENSEMANAGER_H

#include <vector>
#include "Expense.h"

using namespace std;

class ExpenseManager {

private:
    vector<Expense> expenses;

public:
    void addExpense(Expense expense);

    void viewExpenses();

    double getTotalExpense();

    void deleteExpense(int index);

    void saveToFile();

    void loadFromFile();
};

#endif

