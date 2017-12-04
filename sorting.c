#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define SIZE 10

typedef enum { false, true } bool;

int array1[SIZE];
int array2[SIZE];
int array3[SIZE];
bool sorted = true;

float processTime(struct timeval t0, struct timeval t1);

int printArray() {
    for(int i = 0; i<SIZE; i++) {
        printf("%d ", array1[i]);
    }
    printf("\n");
}

int checkSorting() {
    for(int i = 0; i<SIZE; i++) {
        if(array1[i] > array1[i+1]) {
            sorted = false;
            break;
        }
    }

    if(sorted) printf("YES !\n");
    else printf("NO\n");
}

int selectionSort() {    
    int min, i, j;
    struct timeval tStart;
	struct timeval tENd;

    gettimeofday(&tStart, 0);
    for(i = 0; i < SIZE-1; i++) {
        min = i;

        for(j = i+1;j<SIZE;j++)
            if(array1[j] < array1[min]) min = j;

        if(min != i) {
            int temp = array1[min];
            array1[min] = array1[i];
            array1[i] = temp;
        }  
    }
    gettimeofday(&tENd, 0);

    printf("%f ms\n", processTime(tStart, tENd));
}

int insertionSort() {
    int value;
    int add;
    int i;
  
    struct timeval tStart;
	struct timeval tENd;

    gettimeofday(&tStart, 0);
    for(i = 1; i < SIZE; i++) { 
        value = array2[i];
        add = i;

        while (add > 0 && array2[add-1] > value) {
            array2[add] = array2[add-1];
            add--;
        }

        if(add != i) {
            array2[add] = value;
        }
    }
    gettimeofday(&tENd, 0);

    printf("%f ms\n", processTime(tStart, tENd));
}

int bubbleSort() {
    int temp;
    int i,j;

    bool swapped = false;

    struct timeval tStart;
	struct timeval tENd;

    gettimeofday(&tStart, 0);
    for(i = 0; i < SIZE-1; i++) { 
        swapped = false;

        for(j = 0; j < SIZE-1-i; j++) {
            if(array3[j] > array3[j+1]) {
                temp = array3[j];
                array3[j] = array3[j+1];
                array3[j+1] = temp;

                swapped = true;
            }
        }

        if(!swapped) break;
    }
    gettimeofday(&tENd, 0);

    printf("%f ms\n", processTime(tStart, tENd));
}

int main() {
    srand(time(NULL));
    
    for(int i = 0; i<SIZE; i++) {
        array1[i] = rand()%100;
        array2[i] = array1[i];
        array3[i] = array1[i];
    }    
    
    printf("\t         ARRAY : "); printArray();
    printf("\t     IS SORTED : "); checkSorting();
    printf("\tSELECTION SORT : "); selectionSort();
    printf("\tINSERTION SORT : "); insertionSort();
    printf("\t   BUBBLE SORT : "); bubbleSort();
}

float processTime(struct timeval t0, struct timeval t1)
{
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}
