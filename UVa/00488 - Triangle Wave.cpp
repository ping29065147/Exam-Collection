#include <iostream>

using namespace std;

int main()
{
    int n, a, f;
    int i, j, x;
    cin >> n;

    while(n--){
        cin >> a >> f;

        while(f--){
            x=1;
            for(i=1; i>0; i+=x){
                if (i==a)
                    x=-1;
                for(j=1; j<=i; j++)
                    cout << i;
                cout << endl;
            }
            cout << endl;
        }
    }

    return 0;
}
