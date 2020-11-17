#include <iostream>

using namespace std;

int main()
{
    long long family[80], in, a;

    family[1] = 1;
    family[2] = 2;
    for(a=3; a<=80; a++)
        family[a] = family[a-1]+family[a-2];

    while(1){
        cin >> in;
        if (in == 0)
            break;
        cout << family[in] << endl;
    }


    return 0;
}
