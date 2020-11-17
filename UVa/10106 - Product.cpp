#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char CHX[250], CHY[250];
    int sizeX, sizeY, a, sizeproduct, b;
    int X[250], Y[250], P[500];

    while(cin >> CHX >> CHY){
        sizeX = strlen(CHX);
        for(a=0; a<sizeX; a++)
            X[a] = CHX[sizeX - a - 1] - '0';
        sizeY = strlen(CHY);
        for(a=0; a<sizeY; a++)
            Y[a] = CHY[sizeY - a - 1] - '0';

        int x=0, y=0;
        for(a=0; a<sizeX; a++){
            if (X[a] == 0)
                x++;
        }
        for(b=0; b<sizeY; b++){
            if (Y[b] == 0)
                y++;
        }
        if (x==sizeX || y==sizeY){
            cout << "0" << endl;
            continue;
        }

        sizeproduct = sizeX + sizeY;
        for(a=0; a<sizeproduct; a++)
            P[a] = 0;
        for(a=0; a < sizeY; a++){
            for(b=0; b < sizeX; b++)
                P[a+b] += X[b]*Y[a];
        }

        int cpy;
        for(a=0; a < sizeproduct; a++){
            if (P[a] > 9){
                cpy = P[a]%10;
                P[a+1] += P[a]/10;
                P[a] = cpy;
            }
        }

        for(a=sizeproduct; P[sizeproduct-1] == 0; a--)
                sizeproduct--;

        for(a=sizeproduct-1; a>=0; a--)
            cout << P[a];
        cout << endl;
    }



    return 0;
}
