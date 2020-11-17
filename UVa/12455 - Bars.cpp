#include <iostream>

using namespace std;

int main()
{
    int number, n, p, a, result=0, total, b, x;
    cin >> number;

    while(number--){
        cin >> n >> p;
        int plong[p], control[p+1];
        for(a=0; a<p; a++){
            cin >> plong[a];
            control[a] = 1;
        }
        control[p] = 1;

        for(a=0; control[p]!=0;){
            total=0;
            for(x=0; x<p; x++){
                if (control[x])
                    total += plong[x];
                if (total == n){
                    result = 1;
                    goto last;
                }
            }
            cout << "\t" << total << endl;

            control[a]--;
            for(x=0; x<p; x++){
                if (control[x] == -1){
                    control[x] = 1;
                    control[x+1]--;
                }
            }
        }


        last:

        if (result)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;

        result = 0;
    }

    return 0;
}
