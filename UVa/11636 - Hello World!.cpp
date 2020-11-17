#include <iostream>

using namespace std;

int main()
{
    int a, b;
    int input, cpy;

    for(a=1;;a++){
        cpy=0;
        cin >> input;
        if (input < 0)
            break;

        for(b=1; input>b; b*=2)
            cpy++;

        cout << "Case " << a << ": " << cpy << endl;
    }

    return 0;
}
