#ifndef EMPLOYEES_H
#define EMPLOYEES_H
#include "config.h"

#define MAX_EMP 100

typedef struct {
    int id;
    char name[50];
    double salary;
} Employee;

void add_employee(void);
void list_employees(void);
int get_employee_count(void);
double get_total_payroll(void);

#endif
