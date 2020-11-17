#include <stdio.h>
#include <stdlib.h>

int main()
{
    int student, i, j=0, k;
    scanf("%d", &student);
    int score[student+1], copy[student+1];
    for(i=0; i <= student; i++){
        score[i] = 0;
        copy[student] = 0;
    }

    for(i=0; i < student; i++)
        scanf("%d", &score[i]);

    for(i=0; i < student; i++){
        j = 0;
        for(k=0; k < student; k++){
            if (score[i] >= score[k]){
                j++;
            }
        }
        copy[j-1] = score[i];
    }

    printf("\n");
    for(i=0; i < student; i++){
        printf("%d", copy[i]);
        if (i == student-1)
            break;
        printf(" ");
    }

    for(i=student-1; i >= 0; i--){
        if (copy[i]-60 < 0){
            if (i == student-1){
                printf("\nworst case");
                break;
            }
            printf("\n%d", copy[i]);
            printf("\n%d", copy[i+1]);
            break;
        }
        if (copy[0] >= 60){
            printf("\nbest case");
            break;
        }

    }

    return 0;
}


