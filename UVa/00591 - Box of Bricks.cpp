#include <iostream>

using namespace std;

int main()
{
    int n, a, sets=1;
    while(1){
        cin >> n;
        if (n==0)
            break;

        int block[n], average=0, total=0;

        for(a=0; a<n; a++){
            cin >> block[a];
            average+=block[a];
        }
        average/=n;

        for(a=0; a<n; a++){
            if (block[a]<=average)
                total+=(average-block[a]);
        }

        cout << "Set #" << sets;
        cout << "\nThe minimum number of moves is " << total << ".\n";
        sets++;
    }
    return 0;
}
