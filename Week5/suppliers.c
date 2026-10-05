#include <stdio.h>
#include <string.h>

int main() {
    //Declaring Variables 
    char supplierName[100] = "";
    char supplierEmail[50] = "";
    char town[50] = "";
    char phone[20] = "";
    char searchName[100];
    char backupName[100];
    char description[200];
    char supplier1[100] = "ABC Office Supplies";
    char supplier2[100] = "Namibia Stationery";
    int choice;

    while(1) {
        printf("\n====================================\n");
        printf("MUNICIPAL FINANCIAL MANAGEMENT\n");
        printf("====================================\n");
        printf("1. Add Supplier\n");
        printf("2. Display Supplier\n");
        printf("3. Search Supplier\n");
        printf("4. Show Name Length\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        if(choice == 1) {
            printf("Enter the name of the supplier: ");
            fgets(supplierName, sizeof(supplierName), stdin);
            supplierName[strcspn(supplierName, "\n")] = '\0';

            printf("Enter the supplier Email: ");
            fgets(supplierEmail, sizeof(supplierEmail), stdin);
            supplierEmail[strcspn(supplierEmail, "\n")] = '\0';

            printf("Enter the town: ");
            fgets(town, sizeof(town), stdin);
            town[strcspn(town, "\n")] = '\0';

            printf("Enter the phone: ");
            fgets(phone, sizeof(phone), stdin);
            phone[strcspn(phone, "\n")] = '\0';

            
            strcpy(backupName, supplierName);
            strcpy(description, supplierName);
            strcat(description, " operates in ");
            strcat(description, town);
            strcat(description, ".");

            printf("Supplier added!\n");

        } else if(choice == 2) {
            if(strlen(supplierName) == 0) {
                printf("No supplier added yet!\n");
            } else {
                printf("\n--- Supplier Details ---\n");
                printf("Name: %s\n", supplierName);
                printf("Email: %s\n", supplierEmail);
                printf("Town: %s\n", town);
                printf("Phone: %s\n", phone);
                printf("Note: %s\n", description);
            }
        } else if(choice == 3) {
            printf("Enter supplier name to search: ");
            fgets(searchName, sizeof(searchName), stdin);
            searchName[strcspn(searchName, "\n")] = '\0';

            if(strcmp(searchName, supplierName) == 0 || strcmp(searchName, supplier1) == 0 || strcmp(searchName, supplier2) == 0) {
                printf("Supplier found.\n");
            } else {
                printf("Supplier not found.\n");
            }
        } else if(choice == 4) {
            if(strlen(supplierName) == 0) {
                printf("No supplier added yet!\n");
            } else {
                printf("Name length: %lu\n", strlen(supplierName));
            }
        } else if(choice == 5) {
            printf("Exiting...\n");
            break;
        }
    }
    return 0;
}