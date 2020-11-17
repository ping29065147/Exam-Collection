#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number;
    scanf("%d", &number);

    int line[number][2], a, b, total[2], x=0;
    for(a=0; a<number; a++){
        scanf("%d %d", &line[a][0], &line[a][1]);
    }

    while(total[0] != total[1]){
        for(a=0; a<number; a++){
            for(b=a+1; b<number; b++){
                if (line[b][0] >= line[a][0] && line[b][1] <= line[a][1]){
                    line[b][0] = 0;
                    line[b][1] = 0;
                }
                else if (line[b][0] <= line[a][0] && line[b][1] >= line[a][1]){
                    line[a][0] = line[b][0];
                    line[a][1] = line[b][1];
                    line[b][0] = 0;
                    line[b][1] = 0;
                }
                else if (line[b][0] <= line[a][0] && line[b][1] >= line[a][0]){
                    line[a][0] = line[b][0];
                    line[b][0] = 0;
                    line[b][1] = 0;
                }
                else if (line[b][1] >= line[a][1] && line[b][0] <= line[a][1]){
                    line[a][1] = line[b][1];
                    line[b][0] = 0;
                    line[b][1] = 0;
                }
            }
        }
        total[x] = 0;
        for(a=0; a<number; a++)
            total[x]+=(line[a][1] - line[a][0]);

        if (x==0)
            x=1;
        else
            x=0;
    }

    printf("\n%d", total[0]);

    return 0;
}
