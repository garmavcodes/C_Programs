#include <stdio.h>
#include <ctype.h>
#include <string.h>

void string() {
    char str[40];
    printf("enter the string\n");
    fgets(str, 40, stdin);  // read input

    str[strcspn(str, "\n")] = '\0';  // remove newline character
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);  // convert to lowercase
    }

    char original[40];
    strcpy(original, str);  // save original string

    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {  // reverse the string
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }

    printf("the reversed string is:%s\n", str);
    printf("the original string is:%s\n", original);

    if (strcmp(str, original) == 0) {  // check palindrome
        printf("the string is palindrom\n");
    } else {
        printf("the string is not palindrome\n");
    }
}

void number() {
    int n, reverse = 0;
    printf("enter the number :");
    scanf("%d", &n);
    int original = n;  // save original number

    if (n == 0) {
        printf("yes, zero is palindrome\n");
    } else if (n < 0) {
        printf("no,negative numbers are not palindrome\n");
    } else {
        while (n != 0) {  // reverse the number
            int pal = n % 10;
            n = n / 10;
            reverse = (reverse * 10) + pal;
        }
        if (original == reverse) {  // check palindrome
            printf("the number is palindrome\n");
        } else {
            printf("the number is not palindrome\n");
        }
    }
}

int main() {
    int option;
    printf("Which one do you prefer:\n1.string palindrome check\n2.number palindrome check\n");
    scanf("%d", &option);
    getchar();  // consume leftover newline

    if (option == 1) {
        string();  // call string function
    } else if (option == 2) {
        number();  // call number function
    } else {
        printf("invalid option\n");
    }
    return 0;
}