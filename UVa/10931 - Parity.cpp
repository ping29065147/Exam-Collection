#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int i, a, count;
    vector<int> result;

    while(1){

        cin >> i;
        if (i==0)
            break;

        count=0;
        result.clear();
        while(i!=0){
            result.push_back(i%2);
            i /= 2;
        }

        cout << "The parity of ";
        for(a=result.size()-1; a>=0; a--){
            cout << result[a];
            if (result[a]==1)
                count++;
        }
        cout << " is " << count << " (mod 2).\n";
    }

    return 0;
}
