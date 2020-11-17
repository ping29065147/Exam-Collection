#include <stdio.h>
#include <stdlib.h>

int main()
{
    int r, c, m;
    scanf("%d %d %d", &r, &c, &m);

    int matrix[r][c], x, y;
    for(x=0;x<r;x++){
        for(y=0;y<c;y++)
            scanf("%d", &matrix[x][y]);
    }

    int control[m];
    for(x=0;x<m;x++)
        scanf("%d", &control[x]);

    int data, z, copy[c][r], spin=0;
    for(z=0;z<m;z++){
        if (control[z] == 1){
            if (spin%2 == 0){
                for(x=0;x<(r/2);x++){
                    for(y=0;y<c;y++){
                        data = matrix[r-1-x][y];
                        matrix[r-1-x][y] = matrix[x][y];
                        matrix[x][y] = data;
                    }
                }
            }
            else{
                for(x=0;x<(c/2);x++){
                    for(y=0;y<r;y++){
                        data = copy[c-1-x][y];
                        copy[c-1-x][y] = copy[x][y];
                        copy[x][y] = data;
                    }
                }
            }
        }
        else{
            spin++;
            if (spin%2 != 0){
                for(x=0;x<c;x++){
                    for(y=0;y<r;y++){
                        copy[x][y] = matrix[r-1-y][x];
                    }
                }
            }
            else{
                for(x=0;x<r;x++){
                    for(y=0;y<c;y++){
                        matrix[x][y] = copy[c-1-y][x];
                    }
                }
            }
        }
    }

    printf("\n");
    if (spin%2 !=0){
        printf("%d %d\n", c, r);
        for(x=0;x<c;x++){
            for(y=0;y<r;y++){
                printf("%d", copy[x][y]);
                if (y != (r-1))
                    printf(" ");
            }
            if (x != (c-1))
                printf("\n");
        }
    }
    else{
        printf("%d %d\n", r, c);
        for(x=0;x<r;x++){
            for(y=0;y<c;y++){
                printf("%d", matrix[x][y]);
                if (y != (c-1))
                    printf(" ");
            }
            if (x != (r-1))
                printf("\n");
        }
    }


    return 0;
}
