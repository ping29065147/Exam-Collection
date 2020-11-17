#include <iostream>

using namespace std;

int main()
{
    int n, k, ni;

    while(cin >> n >> k){
        int sum=n;

        while(n>k-1){
            ni=n/k;

            sum+=ni;
            n=n%k+ni;
        }

        cout << sum << endl;
    }

    return 0;
}
