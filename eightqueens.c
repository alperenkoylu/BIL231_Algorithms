#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

int table[SIZE][SIZE];
int i, j, a, b;

int printTable() {
    for(i=0;i<SIZE;i++) {
        for(j=0;j<SIZE;j++) {
            printf("%d", table[i][j]);
        }
    }
}

int fillHorizontal(int array[a][b]) {
    for(i=0;i<SIZE;i++) {
        if(i!=a)
            array[i][b] = 1;
    }
}

int fillVertical(int array[a][b]) {
    for(i=0;i<SIZE;i++) {
        if(i!=b)
            array[a][i] = 1;
    }
}

int fillDiagonal(int array[a][b]) {
    int exA = a;
    int exB = b;

    while(a = 0 || b = 0) {
        a--;
        b--;
    }

    if(a == 0)
        for(i=0;i<SIZE;i++)
            if(array[i][b] != 2)
                array[i][b++] = 1;
    else if (b == 0)
        for(i=0;i<SIZE;i++)
            if(array[a][i] != 2)
                array[a++][i] = 1;
}

int placeTheQueen(int array[a][b]) {
    array[a][b] = 2;
    fillHorizontal(array[a][b]);
    fillVertical(array[a][b]);
    fillDiagonal(array[a][b]);
}

int main() {


    for(i=0;i<SIZE;i++)
        for(j=0;j<SIZE;j++)
            table[i][j] = 0;

/*
    for(i=0;i<1;i++) {
        for(j=0;j<1;j++) {
            place the
        }
    }
*/
    placeTheQueen(table[0][0]);

    printTable();
}
