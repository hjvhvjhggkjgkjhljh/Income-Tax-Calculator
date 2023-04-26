
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Define a structure to hold the tax payer's information
struct taxpayer {
    char name[50];
    int income;
    float tax;
};
// Function to add a new record
void addRecord(struct taxpayer *taxpayers, int *numTaxpayers) {
// Get the tax payer's name and income
    printf("Enter the tax payer's name: ");
    scanf("%s", taxpayers[*numTaxpayers].name);
    printf("Enter the tax payer's income: ");
    scanf("%d", &taxpayers[*numTaxpayers].income);
// Calculate the tax
if (taxpayers[*numTaxpayers].income <= 500000) {
    taxpayers[*numTaxpayers].tax = 0;
} else if (taxpayers[*numTaxpayers].income <= 1000000) {
    taxpayers[*numTaxpayers].tax = 0.1 *
(taxpayers[*numTaxpayers].income - 500000);
} else {
    taxpayers[*numTaxpayers].tax = 50000 + 0.2 *
(taxpayers[*numTaxpayers].income - 1000000);
    }
// Increment the number of tax payers
(*numTaxpayers)++;
}
// Function to list all tax payers and their taxes
void listRecords(struct taxpayer *taxpayers, int numTaxpayers) {
    printf("Tax Payer\tIncome\tTax\n");
    for (int i = 0; i < numTaxpayers; i++) {
        printf("%s\t\t%d\t%.2f\n", taxpayers[i].name,
taxpayers[i].income, taxpayers[i].tax);
    }
}
// Function to search for a tax payer by name
void searchRecord(struct taxpayer *taxpayers, int numTaxpayers) {
    char name[50];
    printf("Enter the name of the tax payer to search for: ");
    scanf("%s",name);
    for (int i = 0; i < numTaxpayers; i++) {
        if (strcmp(taxpayers[i].name, name) == 0) {
            printf("Tax Payer\tIncome\tTax\n");
            printf("%s\t\t%d\t%.2f\n", taxpayers[i].name,
taxpayers[i].income, taxpayers[i].tax);
            return;
        }
    }
    printf("Tax payer not found.\n");
}
// Function to edit a tax payer's record
void editRecord(struct taxpayer *taxpayers, int numTaxpayers) {
    char name[50];
    printf("Enter the name of the tax payer to edit: ");
    scanf("%s", name);
    for (int i = 0; i < numTaxpayers; i++) {
        if (strcmp(taxpayers[i].name, name) == 0) {
        printf("Enter the new income for %s: ", taxpayers[i].name);
        scanf("%d", &taxpayers[i].income);
// Recalculate the tax
        if (taxpayers[i].income <= 500000) {
            taxpayers[i].tax = 0;
        } else if (taxpayers[i].income <= 1000000) {
            taxpayers[i].tax = 0.1 * (taxpayers[i].income - 500000);
         } else {
            taxpayers[i].tax = 50000 + 0.2 * (taxpayers[i].income -
1000000);
            }
            printf("Record updated.\n");
            return;
        }
    }
    printf("Tax payer not found.\n");
}
// Function to delete a tax payer's record
void deleteRecord(struct taxpayer *taxpayers, int *numTaxpayers) {
    char name[50];
    printf("Enter the name of the tax payer to delete: ");
    scanf("%s", name);
    for (int i = 0; i < *numTaxpayers; i++) {
        if (strcmp(taxpayers[i].name, name) == 0) {
// Shift all the records after this one back by one
            for (int j = i; j < *numTaxpayers - 1; j++) {
                taxpayers[j] = taxpayers[j+1];
            }
// Decrement the number of tax payers
            (*numTaxpayers)--;
            printf("Record deleted.\n");
            return;
        }
    }
    printf("Tax payer not found.\n");
}
int main() {
    struct taxpayer taxpayers[100];
    int numTaxpayers = 0;
    int choice;
    while (1) {
// Display the menu
    printf("\nIncome Tax Calculator\n");
    printf("1. Add New Record\n");
    printf("2. List all Tax Payers along with income tax to be paid.\n");
    printf("3. Search\n");
    printf("4. Edit\n");
    printf("5. Delete Record\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            addRecord(taxpayers, &numTaxpayers);
            break;
        case 2:
            listRecords(taxpayers, numTaxpayers);
            break;
        case 3:
            searchRecord(taxpayers, numTaxpayers);
            break;
        case 4:
            editRecord(taxpayers, numTaxpayers);
            break;
        case 5:
            deleteRecord(taxpayers, &numTaxpayers);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }
    return 0;
}
void edit( income *TaxPayer, int numPayerS) {
    char num[10];
    int found=0;
    if(numPayerS==0) {
        printf("Record List is empty!\n");
        return;
    }
    printf("\nPlease Enter the Mobile Number of the Taxpayer to edit: ");
    scanf("%s", num);
    if(strlen(num)!=10){
        system("cls");
        printf("Sorry, Mobile Number must be of 10 Digits!\nPlease Try  Again.\n\n");
        return;
    }
    int i;
    float new_income;
    system("cls");
    for(i=0; i<numPayerS; i++) {
    if(strcmp(TaxPayer[i].mobile_num,num)==0) {
        printf("\nRecord Found!\nTaxpayer: %s %s\nMobile Number: %s\nIncome: %.2f\nTax to be Paid: %.2f\n",
TaxPayer[i].first_name,TaxPayer[i].last_name,TaxPayer[i].mobile_num,
TaxPayer[i].income, TaxPayer[i].tax);
        printf("\nEnter new income for the taxpayer: ");
        scanf("%f", &new_income);
        if(new_income<0){ // Income must be +ve
        system("cls");
        printf("Sorry, Income can't be negative!\nPlease Try Again.\n\n");
        return;
    }
        TaxPayer[i].income=new_income; //Assigning value to the indice of income
        caltax(TaxPayer[i].income,&TaxPayer[i].tax);
        system("cls");
        printf("\nRecord updated successfully!\n");
        found = 1;
        break;
    }
}
if(found==0) {
    printf("\nRecord not found!\n");
}
}
void delete(income *TaxPayer, int *numPayerS) {
    char num[10];
    int found=0;
    if(*numPayerS==0) {
        printf("Record List is empty!\n");
        return;
    }
    printf("\nPlease Enter the Mobile Number of the Taxpayer to delete: ");
    scanf("%s", num);
    if(strlen(num)!=10){
        system("cls");
        printf("Sorry, Mobile Number must be of 10 Digits!\nPlease Try Again.\n\n");
        return;
    }
    int i;
    system("cls");
    for(i=0; i<*numPayerS; i++) {
    if(strcmp(TaxPayer[i].mobile_num,num)==0) {
        printf("\nRecord Found!\nTaxpayer: %s %s\nMobile Number: %s\nIncome: %.2f\nTax to be Paid: %.2f\n",
TaxPayer[i].first_name,TaxPayer[i].last_name,TaxPayer[i].mobile_num,
TaxPayer[i].income, TaxPayer[i].tax); // Loop to shift the value at the previous indice as the element is Found
        int j;
        for(j=i; j<(*numPayerS)-1; j++) { //Removing the indice of the data that need to be deleted
            TaxPayer[j] = TaxPayer[j+1];
        }
        *numPayerS=*numPayerS-1;
        printf("\nRecord deleted successfully!\n");
        found = 1;
        break;
    }
}
if(found==0) {
    printf("\nRecord not found!\n");
}
}
void caltax(float income,float *tax){
// We will find the tax of the user using tax brackets
    if (income <= 250000) {
        *tax = 0;
    } else if (income > 250000 && income <= 500000) {
        *tax = (income - 250000) * 0.05;
    } else if (income > 500000 && income <= 1000000) {
         *tax = (income - 500000) * 0.2 + 12500;
    } else {
        *tax = (income - 1000000) * 0.3 + 112500;
    }
}