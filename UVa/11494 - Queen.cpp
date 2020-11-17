#include <iostream>

using namespace std;

int main()
{
    int x1, y1, x2, y2;
    int step;

    while(1){
        step=0;
        cin >> x1 >> y1 >> x2 >> y2;

        if (x1==0 && y1==0 && x2==0 && y2==0)
            break;

        if (x1==x2 && y1==y2)
            ;
        else if (x1==x2 || y1==y2 || x1+y1==x2+y2 || x1-y1==x2-y2)
            step=1;
        else
            step=2;


        cout << step << endl;
    }

    return 0;
}
