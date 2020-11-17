#include <iostream>

using namespace std;

int main()
{
    int number, a, total=0, enter;
    cin >> enter;

    while(enter--){
        cin >> number;
        for(a=1; a<number; a++){
            if (number%a == 0)
                total += a;
        }
        if (total == number)
            cout << "perfect";
        else if (total > number)
            cout << "abundant";
        else
            cout << "deficient";
        total=0;
        cout << endl;
    }

    return 0;
}
