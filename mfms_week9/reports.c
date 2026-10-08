#include <stdio.h>
#include "reports.h"
#include "employees.h"
#include "budget.h"

// This module calls functions from employees and budget - as required for extension
void generate_payroll_report(void) {
    printf("\n=== PAYROLL REPORT ===\n");
    printf("Total Employees: %d\n", get_employee_count());
    printf("Total Payroll Cost: $%.2f\n", get_total_payroll());
}

void generate_budget_report(void) {
    printf("\n=== BUDGET REPORT ===\n");
    show_budget();
}

void generate_summary_report(void) {
    printf("\n=== SUMMARY REPORT ===\n");
    printf("Employees: %d\n", get_employee_count());
    printf("Payroll: $%.2f\n", get_total_payroll());
    printf("Balance: $%.2f\n", get_balance());
    if (get_balance() < get_total_payroll()) {
        printf("WARNING: Balance low for payroll!\n");
    }
}