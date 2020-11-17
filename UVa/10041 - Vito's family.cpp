#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, num, a;
    cin >> n;

    while(n--){
        cin >> num;
        int s[num], mid, sum=0;
        for(a=0; a<num; a++)
            cin >> s[a];

        sort(s, s+num);
        if (num%2==1)
            mid = s[(num-1)/2];
        else
            mid = (s[num/2]+s[num/2-1])/2;

        for(a=0; a<num; a++)
            sum += mid-s[a]>0 ? mid-s[a] : s[a]-mid;

        cout << sum << endl;
    }

    return 0;
}
