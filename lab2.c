#include <stdio.h>

int main() {
    // A. Employee salaries
    float salaries[50];
    int i, j;
    float sum = 0, average, highest, lowest, search;
    int found;

    // B. Department budgets
    float budgets[10];
    float totalBudget = 0, avgBudget, temp;

    // --- PART A: Capture 50 salaries ---
    printf("=== MUNICIPAL SYSTEM - EMPLOYEE SALARIES ===\n");
    printf("Enter 50 salaries:\n");
    for (i = 0; i < 50; i++) {
        printf("Salary %d: ", i+1);
        scanf("%f", &salaries[i]);
        sum += salaries[i];
    }

    // Display all salaries
    printf("\n--- All Salaries ---\n");
    for (i = 0; i < 50; i++) {
        printf("Employee %d: %.2f\n", i+1, salaries[i]);
    }

    // Calculate average
    average = sum / 50;
    printf("\nAverage Salary: %.2f\n", average);

    // Find highest and lowest
    highest = salaries[0];
    lowest = salaries[0];
    for (i = 1; i < 50; i++) {
        if (salaries[i] > highest) {
            highest = salaries[i];
        }
        if (salaries[i] < lowest) {
            lowest = salaries[i];
        }
    }
    printf("Highest Salary: %.2f\n", highest);
    printf("Lowest Salary: %.2f\n", lowest);

    // Search for a particular salary
    printf("\nEnter salary to search: ");
    scanf("%f", &search);
    found = 0;
    for (i = 0; i < 50; i++) {
        if (salaries[i] == search) {
            printf("Salary %.2f found at position %d\n", search, i+1);
            found = 1;
        }
    }
    if (!found) {
        printf("Salary %.2f not found.\n", search);
    }

    // --- PART B: Department budgets ---
    printf("\n=== DEPARTMENT BUDGETS ===\n");
    printf("Enter 10 department budgets:\n");
    for (i = 0; i < 10; i++) {
        printf("Budget %d: ", i+1);
        scanf("%f", &budgets[i]);
        totalBudget += budgets[i];
    }

    // Display budgets
    printf("\n--- All Budgets ---\n");
    for (i = 0; i < 10; i++) {
        printf("Department %d: %.2f\n", i+1, budgets[i]);
    }

    // Total and Average
    avgBudget = totalBudget / 10;
    printf("\nTotal Budget: %.2f\n", totalBudget);
    printf("Average Budget: %.2f\n", avgBudget);

    // Sort budgets lowest to highest (Bubble Sort)
    for (i = 0; i < 10 - 1; i++) {
        for (j = 0; j < 10 - 1 - i; j++) {
            if (budgets[j] > budgets[j+1]) {
                temp = budgets[j];
                budgets[j] = budgets[j+1];
                budgets[j+1] = temp;
            }
        }
    }

    printf("\n--- Sorted Budgets (Lowest to Highest) ---\n");
    for (i = 0; i < 10; i++) {
        printf("%.2f\n", budgets[i]);
    }

    return 0;
}