#include <iostream>

using namespace std;

int main()
{
    int T, a, b;
    long long side[3];

    cin >> T;
    for(a=1; a<=T; a++){
        for(b=0; b<3; b++)
            cin >> side[b];

        cout << "Case " << a << ": ";

        for(b=0; b<3; b++){
            if (side[b]<=0){
                cout << "Invalid\n";
                break;
            }
        }
        if (b!=3)
            continue;

        if (side[0]+side[1]<=side[2] || side[1]+side[2]<=side[0] || side[2]+side[0]<=side[1])
            cout << "Invalid\n";
        else if (side[0]==side[1] && side[0]==side[2])
            cout << "Equilateral\n";
        else if (side[0]==side[1] || side[1]==side[2] || side[2]==side[0])
            cout << "Isosceles\n";
        else
            cout << "Scalene\n";
    }

    return 0;
}
