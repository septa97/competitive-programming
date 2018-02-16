#include <stdio.h>
#include <string.h>

int main() {
    char letters[10] = "BFTLC";
    char input[10];
    char *c = letters;
    int n = 0;

    scanf("%s", input);

    while (*c) {
        if (!strchr(input, *c)) {
            printf("%c\n", *c);
            n++;
        }

        c++;
    }

    if (!n) {
        printf("NO MISSING PARTS\n");
    }

    return 0;
}

