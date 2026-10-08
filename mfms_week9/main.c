#include <stdio.h>
#include "config.h"
#include "employees.h"
#include "budget.h"
#include "reports.h"
#include "utilities.h"

void show_menu() {
    printf("\n--- MicroFinance Management System ---\n");
    printf("1. List Employees\n");
    printf("2. Add Income\n");
    printf("3. Add Expense\n");
    printf("4. Show Budget\n");
    printf("5. Payroll Report\n");
    printf("6. Budget Report\n");
    printf("7. Summary Report\n");
    printf("0. Exit\n");
    printf("Choose: ");
}

int main() {
    int choice;
    float amount;
    
    do {
        show_menu();
        if (scanf("%d", &choice) != 1) {
            clear_input_buffer();
            printf("Invalid input!\n");
            continue;
        }
        switch (choice) {
            case 1: 
                list_employees(); 
                break;
            case 2: 
                printf("Enter income amount: ");
                scanf("%f", &amount);
                add_income(amount); 
                break;
            case 3: 
                printf("Enter expense amount: ");
                scanf("%f", &amount);
                add_expense(amount); 
                break;
            case 4: 
                show_budget(); 
                break;
            case 5: 
                generate_payroll_report(); 
                break;
            case 6: 
                generate_budget_report(); 
                break;
            case 7: 
                generate_summary_report(); 
                break;
            case 0: 
                printf("Exiting...\n"); 
                break;
            default: 
                printf("Invalid choice!\n");
        }
    } while (choice != 0);
    return 0;
}