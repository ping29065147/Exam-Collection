#include <iostream>

using namespace std;

int main()
{
    int h1, m1, h2, m2;
    int sleep, different;

    while(1){
        sleep=0;
        cin >> h1 >> m1 >> h2 >> m2;

        if (h1==0 && m1==0 && h2==0 && m2==0)
            break;

        if (h1==h2 && m1<=m2)
            sleep += m2-m1;
        else{
            sleep += 60-m1;
            m1=0;
            h1++;
            if (h1==24)
                h1=0;
            sleep += m2;

            different = h2-h1;
            if (different < 0)
                different+=24;
            sleep += different*60;
        }


        cout << sleep << endl;
    }

    return 0;
}
