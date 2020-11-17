#include <iostream>

using namespace std;

int main()
{
    long long wall[50], a, n;

    wall[0] = 1;
    wall[1] = 2;
    for(a=2; a<50; a++)
        wall[a] = wall[a-2]+wall[a-1];

    while(1){
        cin >> n;
        if (n == 0)
            break;

        cout << wall[n-1] << endl;
    }

    return 0;
}
