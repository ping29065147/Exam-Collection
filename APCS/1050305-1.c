#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number;
    scanf("%d", &number);   //input the number of people

    int score[number], a;
    for(a=0;a<number;a++)
        scanf("%d", &score[a]); //input the score of each person

    int pass=101, fail=-1;
    for(a=0;a<number;a++){
        if (score[a] >= 60){
            if (score[a] < pass)
                pass = score[a];    //find the minimum of pass
        }
        else{
            if (score[a] > fail)
                fail = score[a];    //find the maximum of fail
        }
    }

    if (pass == 101)
        printf("%d\nworst case", fail);
    else if (fail == -1)
        printf("best case\n%d", pass);
    else
        printf("%d\n%d", fail, pass);   //output the answers

    return 0;
}
