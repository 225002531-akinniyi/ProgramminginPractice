#include <stdio.h>

int main(){
   //Declare variables
    double Balance=0;
    double Expense=0;
    double Revenue=0;

    //Welcome Message
    printf("MUNICIPAL BUDGET CALCULATOR\n");

    //User prompt REVENUE
    printf("Please Enter the total revenue: ");
    scanf("%lf", &Revenue);

    //User prompt EXPENSE
    printf("Please Enter the total expense: ");
    scanf("%lf", &Expense);

    //Balance Calculation
    Balance=Revenue-Expense;

    //Display Revenue, Expense and Balance
    printf("Revenue: %.2lf\n", Revenue);
    printf("Expense: %.2lf\n", Expense);
    printf("Balance: %.2lf\n", Balance);


    return 0;
}