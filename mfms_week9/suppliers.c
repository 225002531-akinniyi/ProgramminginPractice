#include <stdio.h>
#include "suppliers.h"
#include "config.h"

typedef struct {
    int id;
    char name[50];
    char contact[50];
} Supplier;

static Supplier suppliers[MAX_SUPPLIERS];
static int supplier_count = 0;

void add_supplier() {
    if (supplier_count >= MAX_SUPPLIERS) {
        printf("Cannot add more suppliers. Max is %d\n", MAX_SUPPLIERS);
        return;
    }
    Supplier s;
    printf("Enter Supplier ID: ");
    scanf("%d", &s.id);
    printf("Enter Supplier Name: ");
    scanf(" %[^\n]", s.name);
    printf("Enter Contact: ");
    scanf(" %[^\n]", s.contact);

    suppliers[supplier_count++] = s;
    printf("Supplier added successfully!\n");
}

void list_suppliers() {
    if (supplier_count == 0) {
        printf("No suppliers.\n");
        return;
    }
    printf("\n--- Supplier List ---\n");
    for (int i = 0; i < supplier_count; i++) {
        printf("%d | %s | %s\n", suppliers[i].id, suppliers[i].name, suppliers[i].contact);
    }
}