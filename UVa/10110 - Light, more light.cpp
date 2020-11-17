#include <iostream>

using namespace std;

int main()
{
    unsigned int n, a;
    bool last;

    while(1){
        last=false;
        cin >> n;
        if (!n)
            break;

        for(a=1; a*a<=n; a++){
            if (a*a==n)
                last=true;
        }


        if (last)
            cout << "yes\n";
        else
            cout << "no\n";
    }

    return 0;
}
