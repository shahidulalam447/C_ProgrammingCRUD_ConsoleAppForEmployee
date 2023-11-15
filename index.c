#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    int id;
    char name[50];
    char position[50];
    float salary;
    char department[50];
};

void createEmployee(struct Employee *employees, int *numEmployees);
void readEmployees(const struct Employee *employees, int numEmployees);
void updateEmployee(struct Employee *employees, int numEmployees);
void deleteEmployee(struct Employee *employees, int *numEmployees);

int main() {
    struct Employee employees[100];
    int numEmployees = 0;
    int choice;

    do {
        printf("\nEmployee Information System\n");
        printf("1. Add Employee\n");
        printf("2. View Employees\n");
        printf("3. Update Employee\n");
        printf("4. Delete Employee\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createEmployee(employees, &numEmployees);
                break;
            case 2:
                readEmployees(employees, numEmployees);
                break;
            case 3:
                updateEmployee(employees, numEmployees);
                break;
            case 4:
                deleteEmployee(employees, &numEmployees);
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 5);

    return 0;
}

void createEmployee(struct Employee *employees, int *numEmployees) {
    if (*numEmployees < 100) {
        printf("Enter Employee ID: ");
        scanf("%d", &employees[*numEmployees].id);

        printf("Enter Name: ");
        getchar();  // Consume the newline character left by previous scanf
        fgets(employees[*numEmployees].name, sizeof(employees[*numEmployees].name), stdin);
        strtok(employees[*numEmployees].name, "\n");  // Remove trailing newline

        printf("Enter Position: ");
        fgets(employees[*numEmployees].position, sizeof(employees[*numEmployees].position), stdin);
        strtok(employees[*numEmployees].position, "\n");

        printf("Enter Salary: ");
        scanf("%f", &employees[*numEmployees].salary);

        printf("Enter Department: ");
        getchar();  // Consume the newline character left by previous scanf
        fgets(employees[*numEmployees].department, sizeof(employees[*numEmployees].department), stdin);
        strtok(employees[*numEmployees].department, "\n");

        (*numEmployees)++;
        printf("Employee added successfully!\n");
    } else {
        printf("Maximum number of employees reached.\n");
    }
}

void readEmployees(const struct Employee *employees, int numEmployees) {
    if (numEmployees > 0) {
        printf("\nEmployee List:\n");
        printf("ID\t\tName\t\tPosition\t\tSalary\t\tDepartment\n");

        for (int i = 0; i < numEmployees; ++i) {
            printf("%d\t\t%s\t\t%s\t\t%.2f\t\t%s\n", employees[i].id, employees[i].name, employees[i].position, employees[i].salary, employees[i].department);
        }
    } else {
        printf("No employees in the system.\n");
    }
}

void updateEmployee(struct Employee *employees, int numEmployees) {
    int id, found = 0;

    if (numEmployees > 0) {
        printf("Enter the Employee ID to update: ");
        scanf("%d", &id);

        for (int i = 0; i < numEmployees; ++i) {
            if (employees[i].id == id) {
                // Display current information
                printf("\nCurrent Employee Information:\n");
                printf("ID\tName\tPosition\tSalary\tDepartment\n");
                printf("%d\t%s\t%s\t%.2f\t%s\n",
                       employees[i].id, employees[i].name, employees[i].position,
                       employees[i].salary, employees[i].department);

                // Allow user to input new data
                printf("\nEnter new Name: ");
                getchar();  // Consume the newline character left by previous scanf
                fgets(employees[i].name, sizeof(employees[i].name), stdin);
                strtok(employees[i].name, "\n");  // Remove trailing newline

                printf("Enter new Position: ");
                fgets(employees[i].position, sizeof(employees[i].position), stdin);
                strtok(employees[i].position, "\n");

                printf("Enter new Salary: ");
                char salaryInput[20];
                fgets(salaryInput, sizeof(salaryInput), stdin);
                if (strlen(salaryInput) > 1) {  // Check if user entered something
                    sscanf(salaryInput, "%f", &employees[i].salary);
                }

                printf("Enter new Department: ");
                getchar();  // Consume the newline character left by previous scanf
                fgets(employees[i].department, sizeof(employees[i].department), stdin);
                strtok(employees[i].department, "\n");

                found = 1;
                printf("Employee information updated successfully!\n");
                break;
            }
        }

        if (!found) {
            printf("Employee with ID %d not found.\n", id);
        }
    } else {
        printf("No employees in the system.\n");
    }
}

void deleteEmployee(struct Employee *employees, int *numEmployees) {
    int id, found = 0;

    if (*numEmployees > 0) {
        printf("Enter the Employee ID to delete: ");
        scanf("%d", &id);

        for (int i = 0; i < *numEmployees; ++i) {
            if (employees[i].id == id) {
                for (int j = i; j < *numEmployees - 1; ++j) {
                    employees[j] = employees[j + 1];
                }

                (*numEmployees)--;
                found = 1;
                printf("Employee deleted successfully!\n");
                break;
            }
        }

        if (!found) {
            printf("Employee with ID %d not found.\n", id);
        }
    } else {
        printf("No employees in the system.\n");
    }
}
