
#include "Expense.h"

Expense::Expense(double amt, string cat, string nt) {

    amount = amt;
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

