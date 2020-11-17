#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    while(n--){

        int e, f, c, bottle, drink=0, left_bottle;
        cin >> e >> f >> c;

        bottle = e+f;
        while(bottle >= c){
            left_bottle = bottle%c;
            bottle /= c;

            drink += bottle;
            bottle += left_bottle;
        }

        cout << drink << endl;
    }

    return 0;
}
