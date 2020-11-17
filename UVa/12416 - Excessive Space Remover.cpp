#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int main()
{

    string in;
    int len, a, times, re;

    while(getline(cin, in)){
        vector<char> input(in.begin(), in.end());
        len = input.size();

        times=0;
        re=1;
        while(re){
            for(a=0; a<len-1; a++){
                if (input[a]-' '==0 && input[a+1]-' '==0){
                    input.erase(input.begin()+a);
                    len--;
                    re++;
                }
            }
            if (re>1){
                re=1;
                times++;
            }
            else
                re=0;

        }

        cout << times << endl;
    }



    return 0;
}
