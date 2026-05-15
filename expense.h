
#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>
using namespace std;

class Expense {

private:
    double amount;
    string category;
    string note;

public:
    Expense(double amt, string cat, string nt);

    double getAmount();

    string getCategory();

    string getNote();
};

#endif

