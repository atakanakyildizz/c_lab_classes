#include <stdio.h>
#include <ctype.h>
#include <string.h>

int countSpaces(char *s) {
    if (*s == '\0') {
        return 0;
    }
    if (isspace(*s)) {
        return 1 + countSpaces(s + 1);
    }
    return countSpaces(s + 1);
}

int main() {
    char s[100];

    printf("Enter a string: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0';
    int spaces = countSpaces(s);
    printf("Number of white-space characters: %d\n", spaces);

    return 0;
}
