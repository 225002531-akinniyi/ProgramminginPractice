#include <stdio.h>

int main(){
  //Declare variables
  char supplierName[50]; 
  double price=0.00; 
  double budget=0.00; 
  int registered; 
  int documentsComplete;   

  //Ask user for Supplier name
  printf("Enter supplier name: "); 
  scanf("%s", supplierName); 

  //Ask user for Price
  printf("Enter supplier price: "); 
  scanf("%f", &price);

  //Ask user for Budget
  printf("Enter available budget: "); 
  scanf("%f", &budget);

  //Ask user for Registration status
  printf("Is supplier registered? (1=Yes, 0=No): "); 
  scanf("%d", &registered);

  //Ask user for Documents completed
  printf("Are all documents complete? (1=Yes, 0=No): "); 
  scanf("%d", &documentsComplete); 

  //Check if qualified
  if (registered == 0 || documentsComplete == 0) 
  { 
  printf("\nSupplier: %s\n", supplierName); 
  printf("Status: Disqualified\n"); 
  } 
  else if (price > budget) 
 { 
  printf("\nSupplier: %s\n", supplierName); 
  printf("Status: Disqualified\n"); 
  } 
  else 
  { 
  printf("\nSupplier: %s\n", supplierName); 
  printf("Status: Qualified\n"); 
  } 
  return 0;
}