#include <stdio.h>
#include <time.h>

int linearSearch(int array[], int size, int x) {
    for (int i = 0; i < size; i++) {
        if (array[i] == x) {
            return i; 
        }
    }
    return -1; 
}

int binarySearch(int array[], int size, int x) {
    int low = 0;
    int high = size - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (array[mid] == x) {
            return mid; 
        } else if (array[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return -1; 
}

int main() {
    int size = 10000; 
    int array[size];

    for (int i = 0; i < size; i++) {
        array[i] = i;
    }

    int x = 3456; 
    
    clock_t start = clock();
    int linearSearchIndex = linearSearch(array, size, x);
    clock_t end = clock();
    double linearSearchTime = (double)(end - start) / CLOCKS_PER_SEC;

    start = clock();
    int binarySearchIndex = binarySearch(array, size, x);
    end = clock();
    double binarySearchTime = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Tim kiem tuyen tinh:\n");
    if (linearSearchIndex != -1) {
        printf("Tim thay tai vi tri %d\n", linearSearchIndex);
    } else {
        printf("Khong tim thay\n");
    }
    printf("Thoi gian tim kiem: %f giay\n", linearSearchTime);

    printf("\nTim kiem nhi phan:\n");
    if (binarySearchIndex != -1) {
        printf("Tim thay tai vi tri %d\n", binarySearchIndex);
    } else {
        printf("Khong tim thay\n");
    }
    printf("Thoi gian tim kiem: %f giay\n", binarySearchTime);

    return 0;
}
