#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char num1[11], num2[11];
    int n1[11], n2[11], a, maxlen, result;

    while(1){
        cin >> num1 >> num2;

        if (num1[0]=='0' && num2[0]=='0')
            break;

        result=0;
        for(a=0; a<11; a++){
            n1[a]=0;
            n2[a]=0;
        }

        for(a=0; a<strlen(num1); a++)
            n1[strlen(num1)-1-a] = num1[a]-'0';
        for(a=0; a<strlen(num2); a++)
            n2[strlen(num2)-1-a] = num2[a]-'0';

        if (strlen(num1) > strlen(num2))
            maxlen = strlen(num1);
        else
            maxlen = strlen(num2);

        for(a=0; a<=maxlen+1; a++){
            n1[a] += n2[a];
            while(n1[a]>=10){
                result++;
                n1[a+1]++;
                n1[a] -= 10;
            }
        }

        if (result==0)
            cout << "No";
        else
            cout << result;
        cout << " carry operation";
        if (result<=1)
            cout << ".\n";
        else
            cout << "s.\n";
    }

    return 0;
}
