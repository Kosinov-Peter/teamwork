#include <stdio.h>
#include <stdlib.h>

int* Sort_Merge(int* mas, int nach, int kol) {
    if (kol-nach < 2) {
        int* x1 = (int*) malloc(sizeof(int));
        x1[0] = mas[nach];
        return x1;
    }
    int* xleft = Sort_Merge(mas, nach, (kol+nach)/2 ); // Left;..// ++
    int* xright = Sort_Merge(mas, (kol+nach)/2, kol); // Right .. // ++
    int* xresult = (int*) malloc( sizeof(int)* (kol-nach) );   // ++

    int i = (kol-nach) / 2; // for xleft .....// ++
    int j = (kol-nach+1) / 2; // for xright...// ++
//    int lef = xleft[0];
//    int right = xright[0];
    while ( (i > 0) || (j > 0) ) {
        if (i == 0){
            for (j; j > 0; j--){
                xresult[kol - nach - j] = xright[( (kol-nach+1) / 2 ) - j];
            }
            break;
        }
        if (j == 0){
            for (i; i > 0; i--){
                xresult[kol - nach - i] = xleft[( (kol-nach) / 2 ) - i];
            }
            break;
        }
        if (xleft[( (kol-nach) / 2) - i] < xright[( (kol-nach+1) / 2 ) - j]){
            xresult[(kol-nach) - (i+j)] = xleft[( (kol-nach) / 2 ) - i];
            i--;
            continue;
        } else {
            xresult[(kol-nach) - (i+j)] = xright[( (kol-nach+1) / 2 ) - j];
            j--;
            continue;
        }
    }
    free(xleft);
    free(xright);
    return xresult;
}
int main(void) {
    printf("Vvedite kol-vo elementov\n");
    int kol = 0;
    scanf("%d",&kol);
    int* mas = (int*) malloc(kol*sizeof(int));
    for (int i = 0; i < kol; i++ ) {
        scanf("%d",&mas[i]);
    }
    int* result = Sort_Merge(mas,0,kol);
    for (int i = 0; i < kol; i++) {
        printf("%d ",result[i]);
    }
    free(result);
    free(mas);
    return 0;
}

/*




    int* Sort_Merge(int* mas, int nach, int kol) {
        if (kol-nach < 2) {
            int* x1 = (int*) malloc(sizeof(int));
            x1[0] = mas[nach];
            return x1;
        }

        int* xleft = Sort_Merge(mas, nach, (kol+nach)/2 );
        int* xright = Sort_Merge(mas, (kol+nach)/2, kol);

        int* xresult = (int*) malloc( kol-nach) );

        xresult = Merge(xleft,xright);

        return xresult;
    }
*/




