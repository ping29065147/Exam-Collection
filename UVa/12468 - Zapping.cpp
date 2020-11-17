#include <iostream>

using namespace std;

int main()
{
    int start, ending, result;

    while (1){
        cin >> start >> ending;
        if (start == -1)
            break;

        result = start-ending;
        if (result < 0)
            result*=-1;
        if (result >= 50)
            cout << 100-result << endl;
        else
            cout << result << endl;
    }


    return 0;
}
