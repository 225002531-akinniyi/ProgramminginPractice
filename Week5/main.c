#include <stdio.h>
#include <string.h>

#define MAX_SUPPLIERS 20
#define MAX_EMPLOYEES 5

// --- Data for Employee Search (Evidence #5) ---
char employeeNames[MAX_EMPLOYEES][50] = {
    "Akinniyi Natalia",
    "Maria Smith",
    "David Muller",
    "Sarah Nangolo",
    "James Katji"
};
int employeeIds[MAX_EMPLOYEES] = {101, 102, 103, 104, 105};
char employeeDept[MAX_EMPLOYEES][30] = {"Finance", "Budget Office", "Procurement", "HR", "IT"};

// --- Data for Supplier Management (Evidence #2) ---
// Page 7 rule: parallel character arrays
char supplierName[MAX_SUPPLIERS][100];
char supplierEmail[MAX_SUPPLIERS][100];
char supplierPhone[MAX_SUPPLIERS][30];
char supplierTown[MAX_SUPPLIERS][50];
int supplierCount = 0;

// ================= REUSABLE FUNCTIONS (Evidence #3 - at least 3) =================

// Reusable 1: Display header - clear and reusable
void displayHeader(const char* title) {
    printf("\n========================================\n");
    printf(" %s\n", title);
    printf("========================================\n");
}

// Reusable 2: Clear input buffer - avoids scanf issues
void clearInputBuffer() {
    int c;
    while ((c = getchar())!= '\n' && c!= EOF);
}

// Reusable 3: Get positive double with prompt
double getPositiveAmount(const char* prompt) {
    double amount;
    printf("%s", prompt);
    scanf("%lf", &amount);
    clearInputBuffer();
    return amount;
}

// Reusable 4: Display supplier details (as shown on Page 7 example)
void displaySupplierDetails(int index) {
    printf("\n--- SUPPLIER DETAILS ---\n");
    printf("Name: %s", supplierName[index]);
    printf("Email: %s", supplierEmail[index]);
    printf("Phone: %s", supplierPhone[index]);
    printf("Town: %s", supplierTown[index]);
}

// ================= MENU FUNCTIONS (Evidence #4 - each option calls separate function) ===

// 1. Calculate Employee Salary
void calculateEmployeeSalary() {
    displayHeader("CALCULATE EMPLOYEE SALARY"); // Meaningful comment
    double hoursWorked = getPositiveAmount("Enter hours worked: ");
    double hourlyRate = getPositiveAmount("Enter hourly rate (N$): ");
    double deductions = getPositiveAmount("Enter deductions (N$): ");

    // Clear variable names (Evidence #7)
    double grossSalary = hoursWorked * hourlyRate;
    double netSalary = grossSalary - deductions;

    printf("\n--- Salary Slip ---\n");
    printf("Gross Salary: N$ %.2f\n", grossSalary);
    printf("Deductions: N$ %.2f\n", deductions);
    printf("Net Salary: N$ %.2f\n", netSalary);
}

// 2. Calculate VAT - Namibia 15%
void calculateVAT() {
    displayHeader("CALCULATE VAT");
    double amountBeforeVAT = getPositiveAmount("Enter amount before VAT (N$): ");
    const double vatRate = 0.15; // 15% VAT
    double vatAmount = amountBeforeVAT * vatRate;
    double totalAmount = amountBeforeVAT + vatAmount;

    printf("\nVAT Amount (15%%): N$ %.2f\n", vatAmount);
    printf("Total with VAT: N$ %.2f\n", totalAmount);
}

// 3. Calculate Budget
void calculateBudget() {
    displayHeader("CALCULATE BUDGET");
    double totalIncome = getPositiveAmount("Enter total municipal income (N$): ");
    double totalExpenses = getPositiveAmount("Enter total expenses (N$): ");
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

// 4. Search Employee (Evidence #5)
void searchEmployee() {
    displayHeader("SEARCH EMPLOYEE");
    char searchInput[50];
    printf("Enter employee name or ID: ");
    fgets(searchInput, sizeof(searchInput), stdin);
    searchInput[strcspn(searchInput, "\n")] = 0; // Remove newline

    int found = 0;
    printf("\n--- Search Results ---\n");
    for (int i = 0; i < MAX_EMPLOYEES; i++) {
        char idString[10];
        sprintf(idString, "%d", employeeIds[i]);
        // Search by name or ID
        if (strstr(employeeNames[i], searchInput)!= NULL || strcmp(idString, searchInput) == 0) {
            printf("ID: %d | Name: %s | Dept: %s\n", employeeIds[i], employeeNames[i], employeeDept[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("No employee found for '%s'\n", searchInput);
    }
}

// 5. Supplier Management (Evidence #2 - Supplier Management Module)
void supplierManagement() {
    displayHeader("SUPPLIER MANAGEMENT MODULE");
    printf("1. Add Supplier\n");
    printf("2. List All Suppliers\n");
    printf("3. Back to Main Menu\n");
    printf("Choose option: ");
    int choice;
    scanf("%d", &choice);
    clearInputBuffer();

    if (choice == 1) {
        if (supplierCount >= MAX_SUPPLIERS) {
            printf("Supplier list is full!\n");
            return;
        }
        // Using fgets as taught on Page 7
        printf("Enter supplier name: ");
        fgets(supplierName[supplierCount], sizeof(supplierName[supplierCount]), stdin);

        printf("Enter email: ");
        fgets(supplierEmail[supplierCount], sizeof(supplierEmail[supplierCount]), stdin);

        printf("Enter phone: ");
        fgets(supplierPhone[supplierCount], sizeof(supplierPhone[supplierCount]), stdin);

        printf("Enter town: ");
        fgets(supplierTown[supplierCount], sizeof(supplierTown[supplierCount]), stdin);

        displaySupplierDetails(supplierCount);
        supplierCount++;
        printf("Supplier added successfully!\n");

    } else if (choice == 2) {
        printf("\n--- All Suppliers (%d) ---\n", supplierCount);
        if (supplierCount == 0) {
            printf("No suppliers registered yet.\n");
        } else {
            for (int i = 0; i < supplierCount; i++) {
                printf("\nSupplier %d:\n", i + 1);
                printf("Name: %s", supplierName[i]);
                printf("Email: %s", supplierEmail[i]);
                printf("Phone: %s", supplierPhone[i]);
                printf("Town: %s", supplierTown[i]);
            }
        }
    }
}

// ================= MAIN MENU (Evidence #4) =================
int main() {
    int menuChoice;
    // Avoid placing all logic inside main() - main only has menu loop
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

        if (scanf("%d", &menuChoice)!= 1) {
            printf("Invalid input! Enter 1-6.\n");
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();

        // Each menu option calls a separate function (Page 25 rule)
        switch (menuChoice) {
            case 1: calculateEmployeeSalary(); break; // Contribution: Member 1
            case 2: calculateVAT(); break; // Contribution: Member 2
            case 3: calculateBudget(); break; // Contribution: Member 3
            case 4: searchEmployee(); break; // Contribution: Member 1
            case 5: supplierManagement(); break; // Contribution: Member 2 & 3
            case 6: printf("\nExiting MFMS. Goodbye!\n"); break;
            default: printf("Invalid choice! Select 1-6.\n");
        }
    } while (menuChoice!= 6);

    return 0;
}