#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct data{
    int id;
    int num;
};

bool compare(data &a, data &b)
{
    if (a.num == b.num)
        return a.id > b.id;
    return a.num < b.num;
}

int main()
{
    string str;
    int a, b, count=0;
    bool check;
    vector<data> re;

    while(getline(cin, str)){

        re.clear();
        for(a=0; a<str.size(); a++){

            check = true;

            for(b=0; b<re.size(); b++){
                if ((int)str[a] == re[b].id){
                    check = false;
                    break;
                }
            }

            if (check){
                data i;
                i.num = 1;
                i.id = (int)str[a];

                re.push_back(i);
            }
            else
                re[b].num++;

        }

        sort(re.begin(), re.end(), compare);

        for(a=0; a<re.size(); a++)
            cout << re[a].id << " " << re[a].num << endl;
        cout << endl;
    }

    return 0;
}
