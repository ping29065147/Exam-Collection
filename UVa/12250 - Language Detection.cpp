#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int main()
{
    string input;
    int a=0, b;

    while(++a){
        getline(cin, input);

        vector<char> out(input.begin(), input.end());
        if (out[0] == '#')
            break;

        cout << "Case " << a << ": ";

        string hello[6] = {"HELLO", "HOLA", "HALLO", "BONJOUR", "CIAO", "ZDRAVSTVUJTE"};
        string language[6] = {"ENGLISH", "SPANISH", "GERMAN", "FRENCH", "ITALIAN", "RUSSIAN"};
        for(b=0; b<6; b++){
            if (input == hello[b]){
                cout << language[b];
                break;
            }
        }
        if (b==6)
            cout << "UNKNOWN";

        cout << endl;
    }

    return 0;
}
