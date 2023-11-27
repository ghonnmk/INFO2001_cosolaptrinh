#include <stdio.h>
#include <string.h>

struct Employee {
    int employeeId;
    char name[50];
    char position[50];
    float salary;
};

void displayEmployee(const struct Employee* employee) {
    printf("Employee ID: %d\n", employee->employeeId);
    printf("Name: %s\n", employee->name);
    printf("Position: %s\n", employee->position);
    printf("Salary: %.2f\n", employee->salary);
}

void displayAllEmployees(const struct Employee employees[], int size) {
    for (int i = 0; i < size; ++i) {
        displayEmployee(&employees[i]);
        printf("\n");
    }
}

void addEmployee(struct Employee employees[], int* size) {
    const int MAX_EMPLOYEES = 100; // S? lu?ng t?i da nhân viên
    if (*size < MAX_EMPLOYEES) {
        struct Employee newEmployee;
        printf("Enter employee ID: ");
        scanf("%d", &newEmployee.employeeId);
        printf("Enter name: ");
        scanf("%s", newEmployee.name);
        printf("Enter position: ");
        scanf("%s", newEmployee.position);
        printf("Enter salary: ");
        scanf("%f", &newEmployee.salary);

        employees[*size] = newEmployee;
        (*size)++;
        printf("Employee added successfully!\n");
    } else {
        printf("Maximum number of employees reached!\n");
    }
}

void removeEmployee(struct Employee employees[], int* size, int employeeId) {
    int index = -1;
    for (int i = 0; i < *size; ++i) {
        if (employees[i].employeeId == employeeId) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        for (int i = index; i < *size - 1; ++i) {
            employees[i] = employees[i + 1];
        }
        (*size)--;
        printf("Employee removed successfully!\n");
    } else {
        printf("Employee not found!\n");
    }
}

void swapEmployees(struct Employee* employee1, struct Employee* employee2) {
    struct Employee temp = *employee1;
    *employee1 = *employee2;
    *employee2 = temp;
}

void sortEmployeesById(struct Employee employees[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (employees[j].employeeId > employees[j + 1].employeeId) {
                swapEmployees(&employees[j], &employees[j + 1]);
            }
        }
    }
}

int main() {
    const int MAX_EMPLOYEES = 100;
    struct Employee employees[MAX_EMPLOYEES];
    int numEmployees = 0;

    int choice;
    do {
        printf("1. Add an employee\n");
        printf("2. Remove an employee\n");
        printf("3. Display all employees\n");
        printf("4. Sort employees by ID\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1: {
                addEmployee(employees, &numEmployees);
                printf("\n");
                break;
            }
            case 2: {
                int employeeId;
                printf("Enter the employee ID to remove: ");
                scanf("%d", &employeeId);
                removeEmployee(employees, &numEmployees, employeeId);
                printf("\n");
                break;
            }
            case 3: {
                displayAllEmployees(employees, numEmployees);
                printf("\n");
                break;
            }
            case 4: {
                sortEmployeesById(employees, numEmployees);
                printf("Employees sorted by ID!\n");
                printf("\n");
                break;
            }
            case 5: {
                printf("Quitting program...\n");
                break;
            }
            default: {
                printf("Invalid choice!\n");
                printf("\n");
                break;
            }
        }
    } while (choice != 5);

    return 0;
}
