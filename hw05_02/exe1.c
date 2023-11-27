#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int linearSearch(int array[], int size, int x) {
    for (int i = 0; i < size; i++) {
        if (array[i] == x) {
            return i; 
        }
    }
    return -1; 
}
int binarySearchRecursive(int array[], int low, int high, int x) {
    if (low <= high) {
        int mid = low + (high - low) / 2;
        if (array[mid] == x) {
            return mid; 
        } else if (array[mid] > x) {
            return binarySearchRecursive(array, low, mid - 1, x);
        } else {
            return binarySearchRecursive(array, mid + 1, high, x);
        }
    }
    return -1; 
}


int binarySearchIterative(int array[], int size, int x) {
    int low = 0;
    int high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (array[mid] == x) {
            return mid; 
        } else if (array[mid] > x) {
            high = mid - 1;
        } else {
            low = mid + 1;
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
    printf("Tim kiem tuyen tinh: ");
    if (linearSearchIndex != -1) {
        printf("tim thay tai vi tri %d\n", linearSearchIndex);
    } else {
        printf("Khong tim thay\n");
    }
    printf("Thoi gian tim kiem: %f giây\n", linearSearchTime);

    
    start = clock();
    int binarySearchRecursiveIndex = binarySearchRecursive(array, 0, size - 1, x);
    end = clock();
    double binarySearchRecursiveTime = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tim kiem nhi phan : ");
    if (binarySearchRecursiveIndex != -1) {
        printf("tim thay tai vi tri %d\n", binarySearchRecursiveIndex);
    } else {
        printf("Khong tim thay\n");
    }
    printf("Thoi gian tim kiem nhi phan: %f giay\n", binarySearchRecursiveTime);

    
    start = clock();
    int binarySearchIterativeIndex =binarySearchIterative(array, size, x);
    end = clock();
    double binarySearchIterativeTime = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tim kiem nhi phan: ");
    if (binarySearchIterativeIndex != -1) {
        printf("Tim thay tai vi tri %d\n", binarySearchIterativeIndex);
    } else {
        printf("Khong tim thay\n");
    }
    printf("Thoi gian tim kiem nhi phan: %f giây\n", binarySearchIterativeTime);

    return 0;
}
