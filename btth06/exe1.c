#include <stdio.h>


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


int timKiem(int* arr, int size, int x) {
    for (int i = 0; i < size; i++) {
        if (*(arr + i) == x) {
            return i; 
        }
    }
    return -1; 
}

int main() {
    int size;
    printf("Nhap kich thuoc cua mang: ");
    scanf("%d", &size);

    int arr[size];

    nhapMang(arr, size);
    inMang(arr, size);

    int x;
    printf("Nhap phan tu can tim kiem: ");
    scanf("%d", &x);

    int index = timKiem(arr, size, x);
    if (index != -1) {
        printf("Phan tu %d duoc tim thay tai vi tri %d trong mang.\n", x, index);
    } else {
        printf("Phan tu %d khong tim thay trong mang.\n", x);
    }

    return 0;
}
