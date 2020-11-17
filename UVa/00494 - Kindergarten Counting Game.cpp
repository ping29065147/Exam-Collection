#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    string line;
    int n, a;

    while(getline(cin, line)){
        n=1;

        for(a=1; a<line.size(); a++){
            if (((line[a]>='a' && line[a]<='z')||(line[a]>='A' && line[a]<='Z')) && ((!(line[a-1]>='a' && line[a-1]<='z'))&&(!(line[a-1]>='A' && line[a-1]<='Z'))))
                n++;
        }

        cout << n << endl;
    }

    return 0;
}
