#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, a, b;
    cin >> n;

    for(b=1; b<=n; b++){
        int num, total=0;
        string farm;

        cin >> num;
        cin >> farm;

        for(a=0; a<num; a++){
            if (farm[a] == '.'){
                total++;
                a += 2;
            }
        }

        cout << "Case " << b << ": " << total << endl;
    }

    return 0;
}
