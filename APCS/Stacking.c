#include <stdio.h>
#include <stdlib.h>
#define NUM 1000
int sorted_w[NUM];

void sort(int n, int *w)
{
    int i, big = 0, idx=0, j;
    for (j=0; j<n; j++){
        for(i=0; i<n; i++){
            if (w[i] > big){
                big = w[i];
                idx = i;
            }
        }
        w[idx] = 0;
        //printf("%d", idx);
        sorted_w[j] = big;
        big = 0;
    }

}

int main()
{
    int w[NUM], f[NUM];
    int n, i, total = 0;

    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d ", &w[i]);
    }
    for(i=0; i<n; i++){
        scanf("%d", &f[i]);
    }
    sort(n, &w);

    for(i=1; i<n; i++){
        total = total + sorted_w[i]*(n-i);
    }
    
    
    
    printf("%d", total);

 /*   printf("\n%d\n", n);
    for(i=0; i<n; i++){
        printf("%d ", w[i]);
    }
    printf("\n");
    for(i=0; i<n; i++){
        printf("%d ", f[i]);
    }
    printf("\n");
*/
    return 0;
}

