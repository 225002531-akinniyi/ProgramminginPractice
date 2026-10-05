#include <stdio.h>
#include <string.h>

int main() {
    //Declaring Variables
    char supplierName[100];
    char supplierEmail[50];
    char town[50];
    char phone[20];
    char searchName[100];
    char backupName[100];
    char description[200];
    char supplier1[100] = "ABC Office Supplies";

    //1.Ask the user to enter Supplier Name
    printf("Enter the name of the supplier: ");
    fgets(supplierName, sizeof(supplierName), stdin);
    supplierName[strcspn(supplierName, "\n")] = '\0';

    //2.Ask the user to enter the Supplier email
    printf("Enter the supplier Email: ");
    fgets(supplierEmail, sizeof(supplierEmail), stdin);
    supplierEmail[strcspn(supplierEmail, "\n")] = '\0';

    //3.Ask town
    printf("Enter the town: ");
    fgets(town, sizeof(town), stdin);
    town[strcspn(town, "\n")] = '\0';

    //4.Ask phone
    printf("Enter the phone: ");
    fgets(phone, sizeof(phone), stdin);
    phone[strcspn(phone, "\n")] = '\0';

    //Display - Task 1
    printf("\n--- Supplier Details ---\n");
    printf("Supplier Name: %s\n", supplierName);
    printf("Supplier Email: %s\n", supplierEmail);
    printf("Town: %s\n", town);
    printf("Phone: %s\n", phone);

    //Task 2 - String Length using strlen()
    printf("\n--- Task 2: Length ---\n");
    printf("Name length: %lu\n", strlen(supplierName));
    printf("Email length: %lu\n", strlen(supplierEmail));

    //Task 3 - Search using strcmp()
    printf("\n--- Task 3: Search ---\n");
    printf("Enter supplier name to search: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    if(strcmp(searchName, supplierName) == 0 || strcmp(searchName, supplier1) == 0) {
        printf("Supplier found.\n");
    } else {
        printf("Supplier not found.\n");
    }

    //Task 4 - Copy using strcpy()
    printf("\n--- Task 4: Copy ---\n");
    strcpy(backupName, supplierName);
    printf("Original: %s\n", supplierName);
    printf("Backup: %s\n", backupName);

    //Task 5 - Concatenate using strcat()
    printf("\n--- Task 5: Concatenate ---\n");
    strcpy(description, supplierName);
    strcat(description, " operates in ");
    strcat(description, town);
    strcat(description, ".");
    printf("%s\n", description);

    return 0;
}