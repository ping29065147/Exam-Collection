#include <iostream>

using namespace std;

int main()
{
    int T, a, b, c;
    int relate[10], most;
    char web[10][100];
    cin >> T;

    for(a=1; a<=T; a++){
        for(b=0 ;b<10; b++)
            cin >> web[b] >> relate[b];

        cout << "Case #" << a << ":\n";

        most = relate[0];
        for(b=1; b<10; b++){
            if (relate[b] > most)
                most = relate[b];
        }

        for(b=0; b<10; b++){
            if (most == relate[b])
                cout << web[b] << endl;
        }
    }

    return 0;
}
