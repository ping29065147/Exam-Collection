#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, input, a, b, change, count;
    vector<int> data;

    while(cin >> n){

        data.clear();
        while(n--){
            cin >> input;
            data.push_back(input);
        }

        count = 0;
        for(a=0; a<data.size()-1; a++){
            for(b=0; b<data.size()-1-a; b++){
                if (data[b] > data[b+1]){
                    change = data[b];
                    data[b] = data[b+1];
                    data[b+1] = change;
                    count++;
                }
            }
        }

        cout << "Minimum exchange operations : " << count << endl;
    }

    return 0;
}
