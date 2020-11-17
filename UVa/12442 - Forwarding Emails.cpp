#include <iostream>
#include <vector>

using namespace std;

int N, times;
vector<int> u, all, sum;
vector<bool> check;

int findemail(int number)
{
    if (check[number]!=0)
        return 0;

    times++;
    check[number] = true;
    findemail(all[number]);

    return sum[number] = times;

}

int main()
{
    int T, finalnum, finaltimes;
    int a, b, c, enteru, x, y;

    cin >> T;
    for(a=1; a<=T; a++){

        cin >> N;
        u.assign(N+5, -1);
        all.assign(N+5, -1);
        sum.assign(N+5, -1);
        for(b=0; b<N; b++){
            cin >> x >> y;
            u[b] = x;
            all[x] = y;
        }

        finalnum = u[0];
        finaltimes = 1;
        for(b=0; b<N; b++){
            times=1;
            check.assign(N+5, false);
            check[b+1] = true;

            if (sum[b+1]==-1)
                findemail(all[b+1]);
            if (times > finaltimes || (times == finaltimes && b+1 < finalnum)){
                finaltimes = times;
                finalnum = b+1;
            }
        }

        cout << "Case " << a << ": " << finalnum << endl;
    }

    return 0;
}
