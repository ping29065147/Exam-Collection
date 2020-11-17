#include <iostream>

using namespace std;

int main()
{
    int a, b, i;
    int sum;

    while(1){
        sum=0;
        cin >> a >> b;

        if (a==0 && b==0)
            break;

        for(;a<=b;a++){
            for(i=1; i*i<=b; i++){
                if (i*i==a){
                     sum++;
                     break;
                }
            }
        }

        cout << sum << endl;
    }

    return 0;
}
