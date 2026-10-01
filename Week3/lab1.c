#include <stdio.h>

int main(){
    //Declare variables
    double basicSalary=0.00;
    double housing=0.00;
    double transport=0.00;
    double tax=0.00;
    double grossSalary=0.00;
    double netSalary=0.00;

    // Ask user for salary
    printf("Enter Basic salary: ");
    scanf("%f", &basicSalary);

    //Ask user for Housing Allowance
    printf("Enter Housing Allowance: ");
    scanf("%f", &housing);

    //Ask user for transport Allowance
    printf("Enter Transport Allowance: ");
    scanf("%f", &transport);

   //Ask user for tax
   printf("Enter Tax: ");
    scanf("%f", &tax);
 
    // Calculate and output Gross salary
    grossSalary = basicSalary + housing + transport;
    printf("Gross Salary: %.2f\n", grossSalary); 

    // Calculate and output Net Salary
    netSalary = grossSalary - tax;
   printf("Net Salary: %.2f\n", netSalary);
    

    return 0;
}