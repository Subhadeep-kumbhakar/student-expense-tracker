#ifndef EXPENSE_H
#define EXPENSE_H

#include <string>
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

    void display();
};

#endif