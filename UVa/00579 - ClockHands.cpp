#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    int minute;
    float hour, re;
    bool check;

    while(1){

        cin >> str;
        if (str[0]=='0' && str[2]=='0' && str[3]=='0')
            break;

        if (str.size() == 5){
            hour = (str[0]-'0')*10 + str[1]-'0';
            minute = (str[3]-'0')*10 + str[4]-'0';
        }
        else{
            hour = str[0]-'0';
            minute = (str[2]-'0')*10 + str[3]-'0';
        }

        hour *= 30;
        hour += (float)minute/2;
        if (minute%2 == 0)
            check = false;
        else
            check = true;
        minute *= 6;

        re = hour-minute;
        if (re<0)
            re *= -1;
        if (re>180)
            re = 360-re;

        cout << re;
        if (check)
            cout << "00\n";
        else
            cout << ".000\n";
    }

    return 0;
}
