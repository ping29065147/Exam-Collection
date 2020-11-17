#include <iostream>

using namespace std;

int main()
{
    int T, a, b;
    int people[3], mini, maxi;
    cin >> T;

    for(a=1; a<=T; a++){
        for(b=0; b<3; b++)
            cin >> people[b];

        mini=people[0];
        maxi=people[0];
        for(b=1; b<3; b++){
            if (people[b] < mini)
                mini = people[b];
            if (people[b] > maxi)
                maxi = people[b];
        }

        cout << "Case " << a << ": ";
        for(b=0; b<3; b++){
            if (people[b]!=mini && people[b]!=maxi){
                cout << people[b];
                break;
            }
        }
        cout << endl;
    }

    return 0;
}
