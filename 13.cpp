#include <stdio.h>
#include <stdlib.h>

#define FILENAME "employee_records.dat"

// Employee structure
struct Employee {
    int empId;
    char name[50];
    float salary;
};

// Function prototypes
void addRecord();
void displayAllRecords();
void updateRecord();
void deleteRecord();

int main() {
    int choice;

    while (1) {
        printf("\nEmployee Record System\n");
        printf("1. Add Record\n");
        printf("2. Display All Records\n");
        printf("3. Update Record\n");
        printf("4. Delete Record\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                displayAllRecords();
                break;
            case 3:
                updateRecord();
                break;
            case 4:
                deleteRecord();
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void addRecord() {
    struct Employee emp;
    FILE *file;

    file = fopen(FILENAME, "ab");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    printf("Enter Employee ID: ");
    scanf("%d", &emp.empId);
    printf("Enter Name: ");
    scanf("%s", emp.name);
    printf("Enter Salary: ");
    scanf("%f", &emp.salary);

    fwrite(&emp, sizeof(struct Employee), 1, file);

    fclose(file);

    printf("Record added successfully.\n");
}

void displayAllRecords() {
    struct Employee emp;
    FILE *file;

    file = fopen(FILENAME, "rb");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    printf("\nEmployee Records:\n");
    while (fread(&emp, sizeof(struct Employee), 1, file) == 1) {
        printf("ID: %d, Name: %s, Salary: %.2f\n", emp.empId, emp.name, emp.salary);
    }

    fclose(file);
}

void updateRecord() {
    struct Employee emp;
    FILE *file;
    int empId, found = 0;

    file = fopen(FILENAME, "r+b");
    if (file == NULL) {
        printf("Error opening file for reading and writing.\n");
        return;
    }

    printf("Enter Employee ID to update: ");
    scanf("%d", &empId);

    while (fread(&emp, sizeof(struct Employee), 1, file) == 1) {
        if (emp.empId == empId) {
            found = 1;

            printf("Enter new Name: ");
            scanf("%s", emp.name);
            printf("Enter new Salary: ");
            scanf("%f", &emp.salary);

            fseek(file, -sizeof(struct Employee), SEEK_CUR);
            fwrite(&emp, sizeof(struct Employee), 1, file);

            printf("Record updated successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("Record not found.\n");
    }

    fclose(file);
}

void deleteRecord() {
    struct Employee emp;
    FILE *file, *tempFile;
    int empId, found = 0;

    file = fopen(FILENAME, "rb");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    tempFile = fopen("temp.dat", "wb");
    if (tempFile == NULL) {
        printf("Error opening temporary file for writing.\n");
        fclose(file);
        return;
    }

    printf("Enter Employee ID to delete: ");
    scanf("%d", &empId);

    while (fread(&emp, sizeof(struct Employee), 1, file) == 1) {
        if (emp.empId == empId) {
            found = 1;
            printf("Record with ID %d deleted.\n", emp.empId);
        } else {
            fwrite(&emp, sizeof(struct Employee), 1, tempFile);
        }
    }

    if (!found) {
        printf("Record not found.\n");
    }

    fclose(file);
    fclose(tempFile);

    remove(FILENAME);
    rename("temp.dat", FILENAME);
}

