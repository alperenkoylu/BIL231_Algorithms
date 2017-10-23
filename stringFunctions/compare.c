#include <stdio.h>
#include <string.h>

int main () {
    char stringOne[50];
    char stringTwo[50];
    int result = 0;

    strcpy(stringOne, "mustafa");
    strcpy(stringTwo, "alperen");

    result = strcmp(stringOne, stringTwo);

    printf("%d   %s   -   %s\n", result, stringOne, stringTwo);
   
    return(0);
}
