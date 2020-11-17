#include <iostream>

using namespace std;

int main()
{
    int n, m;

    while(cin >> n >> m){
        cout << n-1+n*(m-1) << endl;
    }

    return 0;
}
