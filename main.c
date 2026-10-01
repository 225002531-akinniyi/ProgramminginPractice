#include <stdio.h> 
 
int main() { 
 //Declare variables
    float salary; 
    float total = 0; 
    float highest = 0; 
    float lowest = 0; 
    float average;
    
 //Capture 50 employess
    
    for (int i = 1; i <= 50; i++) { 
 
        printf("Enter salary for employee %d: ", i); 
        scanf("%f", &salary); 
 
        total = total + salary; 
 
        if (i == 1) { 
            highest = salary; 
            lowest = salary; 
        }
         if (salary > highest) { 
            highest = salary; 
        } 
 
        if (salary < lowest) { 
            lowest = salary; 
        } 
    } 
    
 //Calculate average
    average = total / 50;
    
 //Display results
    printf("\n--- Salary Report ---\n"); 
    printf("Average salary: %.2f\n", average); 
    printf("Highest salary: %.2f\n", highest); 
    printf("Lowest salary: %.2f\n", lowest); 
 
    return 0; 
}