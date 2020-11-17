#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> num(1501);
    int a, n2=0, n3=0, n5=0;

    num[0]=1;

    for(a=1; a<1500; a++){

        for(; n2<a; n2++){
            if (num[n2]*2 > num[a-1])
                break;
        }
        for(; n3<a; n3++){
            if (num[n3]*3 > num[a-1])
                break;
        }
        for(; n5<a; n5++){
            if (num[n5]*5 > num[a-1])
                break;
        }

        if (num[n2]*2 < num[n3]*3)
            num[a] = num[n2]*2;
        else
            num[a] = num[n3]*3;

        if (num[a] > num[n5]*5)
            num[a] = num[n5]*5;

    }

    cout << "The 1500'th ugly number is " << num[1499] << ".";

    return 0;
}
