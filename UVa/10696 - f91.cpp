#include <iostream>

using namespace std;

int main()
{
    int N;
    int output;

    while(1){
        cin >> N;

        if (!N)
            break;

        if (N>100)
            output=N-10;
        else{
            output=91;
        }

        cout << "f91(" << N << ") = " << output << endl;
    }

    return 0;
}
