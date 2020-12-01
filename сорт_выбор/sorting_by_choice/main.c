#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Vvedite kol-vo elementov\n");
    int kol = 0;
    scanf("%d",&kol);
    int* mas = (int*) malloc(kol*sizeof(int));
    for (int i = 0; i < kol; i++ ) {
        scanf("%d",&mas[i]);
    }

    int min = 0;
    int dtime = 0;
    for (int i = 0; i < kol-1; i++ ) {
        min = i;
        for (int j = i+1; j < kol; j++ ) {
            if (mas[j] < mas[min]) {
                min = j;
            }
        }
        dtime = mas[i];
        mas[i] = mas[min];
        mas[min] = dtime;
    }

    printf("\n");
    for (int i = 0; i < kol; i++) {
        printf("%d ",mas[i]);
    }
    free(mas);
    return 0;
}


    for ( i = 1 to (kol-1) ) {
        min = i;

        for (int j = i+1; j < kol; j++ ) {
            if (mas[j] < mas[min]) {
                min = j;
            }
        }

        SWAP mas[i] and mas[min];
    }
