#include <stdio.h>
#include <stdlib.h>


void nhapMang(int* arr, int size) {
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < size; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", arr + i);
    }
}


void inMang(int* arr, int size) {
    printf("Cac phan tu cua mang la:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}


void giaiPhongBoNho(int* arr) {
    free(arr);
    printf("Da giai phong bo nho.\n");
}

int main() {
    int size;
    printf("Nhap kich thuoc cua mang: ");
    scanf("%d", &size);

  
    int* arr = (int*)malloc(size * sizeof(int));

    nhapMang(arr, size);
    inMang(arr, size);

    
    giaiPhongBoNho(arr);

    return 0;
}
