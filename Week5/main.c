#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_EMPLOYEES 5
#define MAX_SUPPLIERS 20

//  Data Structures 
typedef struct {
    int id;
    char name[50];
    char department[30];
} Employee;

typedef struct {
    int id;
    char name[50];
    char contact[20];
} Supplier;

// Sample employees for search functionality
Employee employees[MAX_EMPLOYEES] = {
    {101, "Akinniyi Natalia", "Finance"},
    {102, "Maria Smith", "Budget Office"},
    {103, "David Muller", "Procurement"},
    {104, "Sarah Nangolo", "HR"},
    {105, "James Katji", "IT"}
};

Supplier suppliers[MAX_SUPPLIERS];
int supplierCount = 0;



// 1. Display formatted header
void displayHeader(const char* title) {
    printf("\n========================================\n");
    printf(" %s\n", title);
    printf("========================================\n");
}

// 2.Clear input buffer to avoid scanf issues
void clearInputBuffer() {
    int c;
    while ((c = getchar())!= '\n' && c!= EOF);
}

// 3. Get positive double with validation
double getPositiveDouble(const char* prompt) {
    double value;
    while (1) {
        printf("%s", prompt);
        if (scanf("%lf", &value) == 1 && value >= 0) {
            clearInputBuffer();
            return value;
        } else {
            printf("Invalid input. Enter a positive number.\n");
            clearInputBuffer();
        }
    }
}

// 4. Get string input safely
void getStringInput(const char* prompt, char* buffer, int size) {
    printf("%s", prompt);
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = 0; 
}

//  CORE MODULE FUNCTIONS 

// 1. Calculate Employee Salary
void calculateEmployeeSalary() {
    displayHeader("CALCULATE EMPLOYEE SALARY");

    double hoursWorked = getPositiveDouble("Enter hours worked: ");
    double hourlyRate = getPositiveDouble("Enter hourly rate (N$): ");
    double deductions = getPositiveDouble("Enter deductions (N$): ");

    // Calculation logic
    double grossSalary = hoursWorked * hourlyRate;
    double netSalary = grossSalary - deductions;

    printf("\n--- Salary Slip ---\n");
    printf("Gross Salary: N$ %.2f\n", grossSalary);
    printf("Deductions: N$ %.2f\n", deductions);
    printf("Net Salary: N$ %.2f\n", netSalary);
}

// 2. Calculate VAT 
void calculateVAT() {
    displayHeader("CALCULATE VAT (15%)");

    double amount = getPositiveDouble("Enter amount before VAT (N$): ");
    const double vatRate = 0.15;

    double vatAmount = amount * vatRate;
    double totalAmount = amount + vatAmount;

    printf("\nVAT Amount (15%%): N$ %.2f\n", vatAmount);
    printf("Total with VAT: N$ %.2f\n", totalAmount);
}

// 3. Calculate Budget
void calculateBudget() {
    displayHeader("CALCULATE BUDGET");

    double totalIncome = getPositiveDouble("Enter total municipal income (N$): ");
    double totalExpenses = getPositiveDouble("Enter total expenses (N$): ");

    double remainingBudget = totalIncome - totalExpenses;

    printf("\n--- Budget Report ---\n");
    printf("Income: N$ %.2f\n", totalIncome);
    printf("Expenses: N$ %.2f\n", totalExpenses);
    printf("Balance: N$ %.2f\n", remainingBudget);

    if (remainingBudget < 0) {
        printf("WARNING: Budget deficit!\n");
    } else {
        printf("Status: Budget is balanced.\n");
    }
}

// 4. Search Employee 
void searchEmployee() {
    displayHeader("SEARCH EMPLOYEE");

    char searchName[50];
    getStringInput("Enter employee name or ID to search: ", searchName, sizeof(searchName));

    int found = 0;
    printf("\n--- Search Results ---\n");

    for (int i = 0; i < MAX_EMPLOYEES; i++) {
       
        char idStr[10];
        sprintf(idStr, "%d", employees[i].id);

        if (strstr(employees[i].name, searchName)!= NULL || strcmp(idStr, searchName) == 0) {
            printf("ID: %d | Name: %s | Dept: %s\n",
                   employees[i].id, employees[i].name, employees[i].department);
            found = 1;
        }
    }

    if (!found) {
        printf("No employee found matching '%s'.\n", searchName);
        printf("Available employees: 101-105\n");
    }
}

// 5. Supplier Management Module 
void supplierManagement() {
    int choice;
    displayHeader("SUPPLIER MANAGEMENT MODULE");
    printf("1. Add Supplier\n");
    printf("2. List All Suppliers\n");
    printf("3. Back to Main Menu\n");
    printf("Choose option: ");

    if (scanf("%d", &choice)!= 1) {
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    if (choice == 1) {
        if (supplierCount >= MAX_SUPPLIERS) {
            printf("Supplier list full!\n");
            return;
        }
        Supplier newSupplier;
        newSupplier.id = 1000 + supplierCount + 1;

        getStringInput("Enter supplier name: ", newSupplier.name, sizeof(newSupplier.name));
        getStringInput("Enter contact number: ", newSupplier.contact, sizeof(newSupplier.contact));

        suppliers[supplierCount++] = newSupplier;
        printf("Supplier added successfully! ID: %d\n", newSupplier.id);

    } else if (choice == 2) {
        printf("\n--- Supplier List (%d) ---\n", supplierCount);
        if (supplierCount == 0) {
            printf("No suppliers registered yet.\n");
        } else {
            for (int i = 0; i < supplierCount; i++) {
                printf("ID: %d | Name: %s | Contact: %s\n",
                       suppliers[i].id, suppliers[i].name, suppliers[i].contact);
            }
        }
    }
}

//MAIN MENU 
int main() {
    int menuChoice;

    // Main program loop
    do {
        displayHeader("MUNICIPAL FINANCIAL MANAGEMENT SYSTEM");
        printf("1. Calculate Employee Salary\n");
        printf("2. Calculate VAT\n");
        printf("3. Calculate Budget\n");
        printf("4. Search Employee\n");
        printf("5. Supplier Management\n");
        printf("6. Exit\n");
        printf("========================================\n");
        printf("Enter your choice (1-6): ");

        // Validate menu input
        if (scanf("%d", &menuChoice)!= 1) {
            printf("Invalid input. Please enter a number 1-6.\n");
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();

        
        switch (menuChoice) {
            case 1:
                calculateEmployeeSalary();
                break;
            case 2:
                calculateVAT();
                break;
            case 3:
                calculateBudget();
                break;
            case 4:
                searchEmployee();
                break;
            case 5:
                supplierManagement();
                break;
            case 6:
                printf("\nExiting MFMS. Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice! Please select 1-6.\n");
        }

    } while (menuChoice!= 6);

    return 0;
}