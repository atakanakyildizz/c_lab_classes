#include <stdio.h>
#include <ctype.h>
#include <string.h>

void cleanString(char *s, char *cleaned) {
    int j = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (isalnum(s[i])) {
            cleaned[j++] = tolower(s[i]);
        }
    }
    cleaned[j] = '\0';
}

int isPalindrome(char *s, int l) {
    if (l <= 1) {
        return 1;
    }

    if (s[0] == s[l - 1]) {
        return isPalindrome(s + 1, l - 2);
    } else {
        return 0;
    }
}

int main() {
    char s[1000];

    printf("Enter a sentence: ");
    fgets(s, sizeof(s), stdin);

    char cleaned[strlen(s) + 1];
    cleanString(s, cleaned);

    int length = strlen(cleaned);

    if (isPalindrome(cleaned, length)) {
        printf("\"%s\" is a palindrome.\n", s);
    } else {
        printf("\"%s\" is not a palindrome.\n", s);
    }

    return 0;
}
