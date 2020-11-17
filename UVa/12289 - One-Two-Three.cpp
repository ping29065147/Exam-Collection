#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int num, a, b, counta, countb, countc;
    cin >> num;

    char words[num][6];
    for(a=0; a<num; a++)
        cin >> words[a];
    char sample[3][6] = {"one", "two", "three"};

    for(a=0; a<num; a++){
        counta=0;
        countb=0;
        countc=0;

        for(b=0; b<strlen(words[a]); b++){
            if (words[a][b] != sample[0][b])
                counta++;
            if (words[a][b] != sample[1][b])
                countb++;
            if (words[a][b] != sample[2][b])
                countc++;
        }
        if (counta <= 1)
            cout << "1\n";
        else if (countb <= 1)
            cout << "2\n";
        else if (countc <= 1)
            cout << "3\n";
    }

    return 0;
}
