#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        long a, b, p;
        scanf("%li %li %li", &a, &b, &p);

        if (a * b == p) {
            printf("POSSIBLE DOUBLE SIGMA\n");
        }
        else {
            printf("16 BIT S/W ONLY\n");
        }
    }
    
    return 0;
}
