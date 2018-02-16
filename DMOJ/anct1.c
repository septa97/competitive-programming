#include <stdio.h>
#include <stdlib.h>

int a[10005];

int main() {
    int n, d, i;
    scanf("%d %d", &n, &d);

    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int min = -1;
    int temp = abs(d);
    for (i = 0; i < n; i++) {
        if (temp % a[i] == 0) {
            if (min == -1) {
                min = a[i];
            }
            else if (temp / a[i] < temp / min) {
                min = a[i];
            }
        }
    }

    if (min == -1) {
        printf("This is not the best time for a trip.\n");
    }
    else {
        printf("%d\n", temp / min);
    }

    return 0;
}
