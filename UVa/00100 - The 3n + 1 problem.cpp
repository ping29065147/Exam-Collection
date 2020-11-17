#include <iostream>
#include <vector>

using namespace std;
vector<long long> lists;


int main()
{
    int a;
    long long n, b;

    for(a=1; a<=1000000; a++){
        for(b=a, n=1; b!=1; n++){

            if (b%2!=0)
                b = b*3+1;
            else
                b /= 2;
        }

        lists.push_back(n);
    }


    int i, j, change;
    long long maxnum;
    while(cin >> i >> j){

        cout << i << " " << j << " ";

        if (i>j){
            change=i;
            i=j;
            j=change;
        }

        maxnum = lists[i-1];
        for(a=i; a<=j; a++){
            if (lists[a-1] > maxnum)
                maxnum = lists[a-1];
        }

        cout << maxnum << endl;
    }

    return 0;
}
