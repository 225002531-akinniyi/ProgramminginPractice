#include <stdio.h>
#include "budget.h"

static float balance = 0.0f;
static float total_income = 0.0f;
static float total_expense = 0.0f;

void add_income(float amount) {
    balance += amount;
    total_income += amount;
}

void add_expense(float amount) {
    balance -= amount;
    total_expense += amount;
}

float get_balance(void) { return balance; }

void show_budget(void) {
    printf("\n--- Budget Status ---\n");
    printf("Total Income: $%.2f\n", total_income);
    printf("Total Expense: $%.2f\n", total_expense);
    printf("Current Balance: $%.2f\n", balance);
}