#include <stdio.h>
#include <stdlib.h>


typedef struct {
    char ten[50];
    char tacGia[50];
    float gia;
} Book;
void nhapSach(Book* sach, int size) {
    printf("Nhap thong tin ve cac quyen sach:\n");
    for (int i = 0; i < size; i++) {
        printf("Sach %d:\n", i + 1);
        printf("Ten sach: ");
        scanf("%s", sach[i].ten);
        printf("Tac gia: ");
        scanf("%s", sach[i].tacGia);
        printf("Gia: ");
        scanf("%f", &sach[i].gia);
    }
}
void hienThiSach(Book* sach, int size) {
    printf("Thong tin ve cac quyen sach:\n");
    for (int i = 0; i < size; i++) {
        printf("Sach %d:\n", i + 1);
        printf("Ten sach: %s\n", sach[i].ten);
        printf("Tac gia: %s\n", sach[i].tacGia);
        printf("Gia: %.2f\n", sach[i].gia);
    }
}
void giaiPhongBoNho(Book* sach) {
    free(sach);
    printf("Da giai phong bo nho.\n");
}
int main() {
    int size;
    printf("Nhap so luong sach: ");
    scanf("%d", &size);   
    Book* sach = (Book*)malloc(size * sizeof(Book));
    nhapSach(sach, size);
    hienThiSach(sach, size);
    giaiPhongBoNho(sach);

    return 0;
}
