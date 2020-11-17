#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int main()
{
    int a;
    bool control=1;
    string lines;

    while(getline(cin, lines)){
        vector<char> linev(lines.begin(), lines.end());

        for(a=0; a<linev.size(); a++){
            if (linev[a] == '\"'){

                linev.erase(linev.begin()+a);
                if (control){
                    linev.insert(linev.begin()+a, '`');
                    linev.insert(linev.begin()+a, '`');
                    control=0;
                }
                else{
                    linev.insert(linev.begin()+a, '\'');
                    linev.insert(linev.begin()+a, '\'');
                    control=1;
                }
            }
        }

        for(a=0; a<linev.size(); a++)
            cout << linev[a];
        cout << endl;
    }

    return 0;
}
