#include <stdio.h>

int main() {
    int N, i = 1, sum = 0;
    
    printf("Nhap so le (N): ");
    scanf("%d", &N);
    
    while (N > 0) {
        sum += i;
        i += 2;
        N--;
    }
    
    printf("Tonng cua %d so le dau tien là: %d\n", N, sum);
    
    return 0;
}
