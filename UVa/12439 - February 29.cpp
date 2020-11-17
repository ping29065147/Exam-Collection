#include <iostream>

using namespace std;

int main()
{
    int T, a, sum, x, y;
    long long b;
    char month[2][10], non;
    struct data{
        int year, month_int, date;
    };
    data day[2];



    cin >> T;
    for(a=1; a<=T; a++){
        sum = 0;

        for(b=0; b<2; b++){
            cin >> month[b] >> day[b].date >> non >> day[b].year;
            if (month[b][0]-'J'==0 && month[b][1]-'a'==0 || (month[b][0]-'F'==0 && (day[b].date!=29 || b==0)))
                day[b].year--;
        }
        //for(b=0; b<2; b++)
        //    cout << day[b].month_int << " " << day[b].date << " " << day[b].year << endl;
        x=day[1].year;
        y=day[0].year;

        sum = (x/4-y/4) - (x/100-y/100) + (x/400-y/400);



        cout << "Case " << a << ": " << sum << endl;
    }

    return 0;
}
