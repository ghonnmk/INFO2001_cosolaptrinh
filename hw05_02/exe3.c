#include <stdio.h>

int main() {
    int numStudents;
    printf("Nhap so luong sinh vien trong lop: ");
    scanf("%d", &numStudents);
    float scores[numStudents];
    for (int i = 0; i < numStudents; i++) {
        printf("Nhap diem cua sinh vien thu %d: ", i + 1);
        scanf("%f", &scores[i]);
    }
    float totalScore = 0;
    for (int i = 0; i < numStudents; i++) {
        totalScore += scores[i];
    }
    float averageScore = totalScore / numStudents;
    printf("Diem trung binh cua lop la: %.2f\n", averageScore);

    return 0;
}
