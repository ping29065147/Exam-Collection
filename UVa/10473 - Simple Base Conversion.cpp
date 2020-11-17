#include <iostream>
#include <string>
#include <vector>

using namespace std;

void turn_to_ten(string n)
{
    int a, num=0, mul=1;

    for(a=n.size()-1; a>=2; a--, mul*=16){
        if (n[a] <= '9')
            num += (n[a]-'0')*mul;
        else
            num += (n[a]-'A'+10)*mul;
    }

    cout << num << endl;
}

void turn_to_sixteen(string n)
{
    int a, num=0, mul=1;
    vector<int> re;

    for(a=n.size()-1; a>=0; a--, mul*=10)
        num += (n[a]-'0')*mul;

    while(num){
        re.push_back(num%16);
        num /= 16;
    }

    cout << "0x";
    for(a=re.size()-1; a>=0; a--){
        if(re[a] <= 9)
            cout << re[a];
        else
            cout << (char)((re[a]-10)+'A');
    }
    cout << endl;

}

int main()
{
    string n;

    while(1){
        cin >> n;

        if (n[0] == '-')
            break;

        if (n.size()>=2 && n[0]=='0' && n[1]=='x')
            turn_to_ten(n);
        else
            turn_to_sixteen(n);
    }

    return 0;
}
