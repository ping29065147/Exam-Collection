#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, a;
    vector<bool> check;

    while(cin >> n){
        int num[n];
        for(a=0; a<n; a++)
            cin >> num[a];

        check.assign(n, false);
        for(a=0; a<n-1; a++){
            if(num[a]-num[a+1]<0)
                check[(num[a]-num[a+1])*-1] = true;
            else
                check[num[a]-num[a+1]] = true;
        }

        for(a=1; a<check.size(); a++){
            if (check[a]==false)
                break;
        }
        if (a==check.size())
            cout << "Jolly\n";
        else
            cout << "Not jolly\n";
    }


    return 0;
}
