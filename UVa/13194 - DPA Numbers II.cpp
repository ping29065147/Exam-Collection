#include <iostream>
#include <string.h>
#include <math.h>
const int digits = 1000000;

using namespace std;
unsigned int num[digits], lists[80000];
unsigned int enter, x[64], xtimes[64];

int main()
{
    unsigned int a, b, t=0, counts=0;

    for(a=2; a<digits; a++){
        while(num[a])
            a++;
        for(b=(a<<1); b<digits; b+=a)
            num[b]++;
        lists[t] = a;
        t++;
    }
    t--;

    cin >> enter;
    long long word, sum=1, total=1, wordcpy;

    while(enter--){
        memset((void*)x, 0, 64*sizeof(int));
        memset((void*)xtimes, 0, 64*sizeof(int));
        cin >> word;
        wordcpy = word;

        for(a=0; a<t; a++){
            if (x[counts])
                counts++;
            while (word%lists[a] == 0){
                x[counts] = lists[a];
                xtimes[counts]++;
                word/=lists[a];
            }
            if (word == 1)
                break;
        }

        for(a=0; x[a]!=0; a++){
            for(b=1; b<=xtimes[a]; b++)
                total += pow(x[a], b);
            sum *= total;
            total = 1;
        }
        cout << "word:" << word << "\t";
        sum*=(word+1);
        sum -= wordcpy;

        if (sum < wordcpy)
            cout << "deficient" << endl;
        else if (sum > wordcpy)
            cout << "abundant" << endl;
        else
            cout << "perfect" << endl;

        sum = 1;
        counts = 0;
    }

    return 0;
}
