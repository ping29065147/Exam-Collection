#include <iostream>

using namespace std;

int main()
{
    int n, f, space, animal, environment;
    long long sum;

    cin >> n;

    while(n--){
        sum=0;
        cin >> f;
        while(f--){
            cin >> space >> animal >> environment;
            sum += space*environment;
        }

        cout << sum << endl;
    }

    return 0;
}
