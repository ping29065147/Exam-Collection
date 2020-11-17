#include <iostream>

using namespace std;

int main()
{
    int n, sum;

    while(cin >> n){
        sum=0;

        sum+=n;
        while(n>1){
            sum+=n/3;
            n = n/3+n%3;
            if (n==2)
                n++;
        }

        cout << sum << endl;
    }

    return 0;
}
