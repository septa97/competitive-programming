#include <stdio.h>
#include <stdlib.h>

int main() {
    char a[10], b[10];
    scanf("%s", a);
    scanf("%s", b);

    int a_num = strtol(a, NULL, 16);
    int b_num = strtol(b, NULL, 16);
    int infinity = strtol("3F3F3F3F", NULL, 16);

    if (a_num + b_num > infinity) {
        printf("Yes\n");
    }
    else {
        printf("No\n");
    }

    return 0;
}
