#include <stdio.h>
#include <string.h>
#include "employees.h"
#include "utilities.h"

static Employee employees[MAX_EMPLOYEES];
static int employee_count = 0;

void add_employee() {
    if (employee_count >= MAX_EMPLOYEES) {
        printf("Cannot add more employees. Max is %d\n", MAX_EMPLOYEES);
        return;
    }

    Employee e;
    printf("Enter ID: ");
    scanf("%d", &e.id);
    printf("Enter Name: ");
    scanf(" %[^\n]", e.name);
    printf("Enter Salary: ");
    scanf("%lf", &e.salary);

    employees[employee_count++] = e;
    printf("Employee added successfully!\n");
}

void list_employees() {
    if (employee_count == 0) {
        printf("No employees.\n");
        return;
    }
    printf("\n--- Employee List ---\n");
    for (int i = 0; i < employee_count; i++) {
        printf("%d | %s | $%.2f\n", employees[i].id, employees[i].name, employees[i].salary);
    }
}

int get_employee_count() {
    return employee_count;
}

double get_total_payroll() {
    double total = 0;
    for (int i = 0; i < employee_count; i++) {
        total += employees[i].salary;
    }
    return total;
}