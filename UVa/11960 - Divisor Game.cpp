#include <iostream>
#include <vector>

#define maxx 1000000
using namespace std;

int main()
{
    // fast io
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // init
    int T, x;
    vector<int> fact, ans;
    fact.assign(maxx + 1, 0);
    ans.assign(maxx + 1, 1);

    // find the smallest factor of 2 - 1000000 (except 1)
    for (long long i = 2; i <= maxx; ++i) if (!fact[i])
    {
        fact[i] = i;
        for (long long j = i * i; j <= maxx; j += i)
            if (!fact[j]) fact[j] = i;
    }

    // count the numbers of factors
    for (long long i = 2; i <= maxx; ++i)
    {
        auto tmp = i;
        while (tmp != 1)
        {
            int f = fact[tmp], cnt = 0;
            while (tmp % f == 0)
            {
                tmp /= fact[tmp];
                ++cnt;
            }
            ans[i] *= (cnt + 1);
        }
    }

    // find the number that has most factors <= i
    int maxn = 2, maxans = ans[2];
    for (long long i = 2; i <= maxx; ++i)
    {
        if (ans[i] >= maxans)
        {
            maxans = ans[i];
            maxn = i;
        }
        ans[i] = maxn;
    }

    cin >> T;
    while (T--)
    {
        cin >> x;
        cout << ans[x] << "\n";
    }

    return 0;
}