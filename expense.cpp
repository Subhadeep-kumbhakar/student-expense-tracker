
#include "Expense.h"

Expense::Expense(double a, string cat, string nt) {

    amount = a;
    category = cat;
    note = nt;
}

double Expense::getAmount() {

    return amount;
}

string Expense::getCategory() {

    return category;
}

string Expense::getNote() {

    return note;
}

