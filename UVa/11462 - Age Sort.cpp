#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, a, input;
    vector<int> age;

    while(1){
        age.assign(101, 0);
        cin >> n;

        if (!n)
            break;

        for(a=0; a<n; a++){
            cin >> input;
            age[input]++;
        }

        for(a=1; a<=100; a++){
            while (age[a]!=0){
                cout << a;
                age[a]--;
                n--;

                if (n)
                    cout << " ";
                else
                    cout << endl;
            }
        }
    }

    return 0;
}
