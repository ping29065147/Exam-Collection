#include <iostream>

using namespace std;

int main()
{
    int start, t[3], total, a, b, c ;

    while(1){
        total = 1080;
        cin >> start >> t[0] >> t[1] >> t[2];
        if (start==0 && t[0]==0 && t[1]==0 && t[2]==0)
            break;

        a=40-(t[0]-start);
        if (a>=40)
            a-=40;
        b=(40+t[1]-t[0]);
        if (b>=40)
            b-=40;
        c=40-(t[2]-t[1]);
        if (c>=40)
            c-=40;

        total += a*9;
        total += b*9;
        total += c*9;

        cout << total << endl;
    }

    return 0;
}
