#include <iostream>

using namespace std;

int main()
{
    int n, a, add;
    long long sum;

    while(1){
        cin >> n;
        if (n < 0)
            break;

        sum = 2;
        if (n == 0)
            cout << "1\n";
        else if (n == 1)
            cout << "2\n";
        else{
            for (a=0, add=2; a<n-1; a++, add++)
                sum += add;
            cout << sum << endl;
        }
    }

    return 0;
}
