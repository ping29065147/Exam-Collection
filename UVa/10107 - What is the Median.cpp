#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, a;
    vector<int> data;

    while(cin >> n){


        if (data.size()==0)
            data.push_back(n);
        else{
            data.insert(lower_bound(data.begin(), data.end(), n), n);
        }


        if(data.size()%2)
            cout << data[(data.size()-1)/2];
        else
            cout << (data[data.size()/2]+data[data.size()/2-1])/2;
        cout << endl;
    }

    return 0;
}
