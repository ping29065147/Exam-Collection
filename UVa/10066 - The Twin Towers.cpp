#include <iostream>
#include <vector>

using namespace std;


int main()
{
    int n1, n2, a, b, input, count=1;
    vector<int> str1, str2;
    vector< vector<int> > list;

    while(1){

        cin >> n1 >> n2;
        if (n1==0 && n2==0)
            break;

        str1.clear();
        str2.clear();
        str1.push_back(0);
        str2.push_back(0);
        for(a=0; a<n1; a++){
            cin >> input;
            str1.push_back(input);
        }
        for(b=0; b<n2; b++){
            cin >> input;
            str2.push_back(input);
        }

        n1++;
        n2++;
        for(a=0; a<list.size(); a++)
            list[a].clear();
        list.clear();
        list.resize(n1);
        for(a=0; a<n1; a++)
            list[a].resize(n2);

        for(a=0; a<n1; a++){
            for(b=0; b<n2; b++){
                list[a][b]=0;
            }
        }

        for(a=1; a<n1; a++){
            for(b=1; b<n2; b++){
                if (str1[a] == str2[b])
                    list[a][b] = list[a-1][b-1]+1;
                else{
                    if (list[a-1][b] > list[a][b-1])
                        list[a][b] = list[a-1][b];
                    else
                        list[a][b] = list[a][b-1];
                }
            }
        }

        cout << "Twin Towers #" << count << endl;
        count++;
        cout << "Number of Tiles : " << list[n1-1][n2-1] << endl << endl;
    }

    return 0;
}
