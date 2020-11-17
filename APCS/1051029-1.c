#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y, z, a, control;
    scanf("%d %d %d", &x, &y, &z);

    if (x>y){
        control = x;
        x = y;
        y = control;
    }
    if (y>z){
        control = y;
        y = z;
        z = control;
    }
    if (x>y){
        control = x;
        x = y;
        y = control;
    }
    printf("%d %d %d\n", x, y, z);

    if (x + y <= z)
        printf("No");
    else if (x*x + y*y < z*z)
        printf("Obtuse");
    else if (x*x + y*y == z*z)
        printf("Right");
    else if (x*x + y*y > z*z)
        printf("Acute");

    return 0;
}
