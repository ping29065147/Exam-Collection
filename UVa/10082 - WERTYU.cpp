#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int main()
{
    int a, b, c;
    char list[4][14] = {"`1234567890-=", "QWERTYUIOP[]\\", "ASDFGHJKL;\'", "ZXCVBNM,./"};

    string input;

    while(getline(cin, input)){
        vector<char> str(input.begin(), input.end());

        for(a=0; a<str.size(); a++){
            for(b=0; b<4; b++){
                for(c=0; c<13; c++){
                    if (str[a] == ' '){
                        cout << " ";
                        goto x;
                    }
                    if (list[b][c] - str[a] == 0){
                        cout << list[b][c-1];
                        goto x;
                    }
                }
            }
            x:
                continue;
        }
        cout << endl;
    }

    return 0;
}
