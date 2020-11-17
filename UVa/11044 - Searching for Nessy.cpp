#include <iostream>

using namespace std;

int main()
{

    int t, n, m;
    int x, y;
    cin >> t;

    while(t--){
        x=0;
        y=0;
        cin >> n >> m;

        while(n>2){
            n-=3;
            x++;
        }
        while(m>2){
            m-=3;
            y++;
        }

        cout << x*y << endl;
    }

    return 0;
}
