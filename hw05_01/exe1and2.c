#include <string.h>
#include <stdio.h>


struct Student {
    char name[50];
    int id;
    float gpa;
};

void displayStudent(const struct Student* student) {
    printf("Name: %s, ID: %d, Gpa: %.2f\n", student->name, student->id, student->gpa);
}

void displayAllStudents(const struct Student students[], int size) {
    for (int i = 0; i < size; ++i) {
        displayStudent(&students[i]);
    }
}

void updateStudent(struct Student* student) {
    printf("Enter new name: ");
    scanf("%s", student->name);
    printf("Enter new ID: ");
    scanf("%d", &student->id);
    printf("Enter new GPA: ");
    scanf("%f", &student->gpa);
}

void swapStudents(struct Student* student1, struct Student* student2) {
    struct Student temp = *student1;
    *student1 = *student2;
    *student2 = temp;
}

void sortStudentsByName(struct Student students[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (strcmp(students[j].name, students[j + 1].name) > 0) {
                swapStudents(&students[j], &students[j + 1]);
            }
        }
    }
}

void sortStudentsByGpa(struct Student students[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (students[j].gpa < students[j + 1].gpa) {
                swapStudents(&students[j], &students[j + 1]);
            }
        }
    }
}

int searchStudentByName(const struct Student students[], int size, const char* name) {
    for (int i = 0; i < size; ++i) {
        if (strcmp(students[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

int searchStudentById(const struct Student students[], int size, int id) {
    for (int i = 0; i < size; ++i) {
        if (students[i].id == id) {
            return i;
        }
    }
    return -1;
}

int main() {
    const int MAX_STUDENTS = 100;
    struct Student students[MAX_STUDENTS];
    int numStudents = 0;

    int choice;
    do {
        printf("1. Add a student\n");
        printf("2. Display all students\n");
        printf("3. Update a student\n");
        printf("4. Sort students by name\n");
        printf("5. Sort students by gpa\n");
        printf("6. Search student by name\n");
        printf("7. Search student by ID\n");
        printf("8. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1: {
                if (numStudents < MAX_STUDENTS) {
                    struct Student newStudent;
                    printf("Enter name: ");
                    scanf("%s", newStudent.name);
                    printf("Enter ID: ");
                    scanf("%d", &newStudent.id);
                    printf("Enter gpa: ");
                    scanf("%f", &newStudent.gpa);

                    students[numStudents] = newStudent;
                    numStudents++;
                } else {
                    printf("Maximum number of students reached!\n");
                }
                break;
            }
            case 2: {
                displayAllStudents(students, numStudents);
                printf("\n");
                break;
            }
            case 3: {
                printf("Enter the index of the student to update: ");
                int index;
                scanf("%d", &index);

                if (index >= 0 && index < numStudents) {
                    updateStudent(&students[index]);
                } else {
                    printf("Invalid index!\n");
                }
                break;
            }
            case 4: {
                sortStudentsByName(students, numStudents);
                printf("Students sorted by name!\n");
                break;
            }
            case 5: {
                sortStudentsByGpa(students, numStudents);
                printf("Students sorted by score!\n");
                break;
            }
            case 6: {
                char name[50];
                printf("Enter the name to search for: ");
                scanf("%s", name);

                int index = searchStudentByName(students, numStudents, name);
                if (index != -1) {
                    printf("Student found at index %d:\n", index);
                    displayStudent(&students[index]);
                } else {
                    printf("Student not found!\n");
                }
                break;
            }
            case 7: {
                int id;
                printf("Enter the ID to search for: ");
                scanf("%d", &id);

                int index = searchStudentById(students, numStudents, id);
                if (index != -1) {
                    printf("Student found at index %d:\n", index);
                    displayStudent(&students[index]);
                } else {
                    printf("Student not found!\n");
                }
                break;
            }
            case 8: {
                printf("Quitting program...\n");
                break;
            }
            default: {
                printf("Invalid choice!\n");
                break;
            }
        }

        printf("\n");
    } while (choice != 8);

    return 0;
}
