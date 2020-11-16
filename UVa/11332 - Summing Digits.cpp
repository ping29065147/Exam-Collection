#include <iostream>

using namespace std;

int f(int n)
{
    if (n-10 < 0)
        return n;
    else{
        int sum=0;
        while(n>0){
            sum += n%10;
            n/=10;
        }
        return f(sum);
    }

}

int main()
{
    int n;

    while(1){
        cin >> n;
        if (n==0)
            break;

        cout << f(n) << endl;
    }


    return 0;
}
