#include "Expense.h"
#include <iostream>

using namespace std;

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

void Expense::display() {
    cout << category << " - ₹" << amount << " - " << note << endl;
}