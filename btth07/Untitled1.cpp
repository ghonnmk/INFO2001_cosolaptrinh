#include <stdio.h>
#include <string.h>
typedef struct {
    int id;
    char name[30];
    float salary;
} Employee;

int main() {
    Employee emp1, emp2;
    FILE *file;

    file = fopen("employees.dat", "wb");
    if (file == NULL) {
        printf("Do not open this file!.\n");
        return 1;
    }

    emp1.id = 1;
    strcpy(emp1.name, "KhanhDaCoNguoiYeuConBanThiSao");
    emp1.salary = 12000000.0;

    fwrite(&emp1, sizeof(Employee), 1, file);

    fclose(file);

    file = fopen("employees.dat", "rb");
    if (file == NULL) {
        printf("Do not open this file!.\n");
        return 1;
    }

    fread(&emp2, sizeof(Employee), 1, file);

    printf("ID: %d\n", emp2.id);
    printf("Name: %s\n", emp2.name);
    printf("Salary: %.2f\n", emp2.salary);

    fclose(file);

    return 0;
}
