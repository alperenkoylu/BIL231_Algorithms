#include <stdio.h>
#include <string.h>

int main () {
   char stringOne[50], stringTwo[50];

   strcpy(stringOne,  "This is source");
   strcpy(stringTwo, "This is destination");

   strcat(stringOne, stringTwo);

   printf("Final string => %s\n", stringTwo);
   
   return(0);
}
