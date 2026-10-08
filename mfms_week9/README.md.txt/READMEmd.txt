-MicroFinance Management System (MFMS) - Week 9

-Project Description
Modular C program for managing employees, budget (income/expense), reports, and suppliers.
Demonstrates separation of concerns using `.h` and `.c` files.

- Module Dependency Diagram
![diagram](diagram.png)

-Dependencies:
- `main.c -> config.h, employees.h, budget.h, reports.h, utilities.h, suppliers.h`
- `employees.c -> employees.h, config.h`
- `budget.c -> budget.h, config.h`
- `reports.c -> reports.h, employees.h, budget.h`
- `utilities.c -> utilities.h, config.h`
- `suppliers.c -> suppliers.h, config.h`

-File Structure