#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int main()
{
    string n;
    int a, total;

    while(1){
        total=0;
        getline(cin, n);
        vector<char> N(n.begin(), n.end());

        if(N[0]=='0')
            break;

        for(a=0; a<N.size(); a++){
            if (a%2)
                total += N[a]-'0';
            else
                total -= N[a]-'0';
        }

        for(a=0; a<N.size(); a++)
            cout << N[a];

        cout << " is ";
        if (total%11!=0)
            cout << "not ";
        cout << "a multiple of 11.\n";
    }

    return 0;
}
