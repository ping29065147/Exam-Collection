#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector< vector<int> > G;
vector<int> low, dfn, V, com;
int dep, cnt;

void dfs(int u)
{
    low[u] = dfn[u] = ++dep;
    V.emplace_back(u);

    for (auto& v : G[u])
        if (!dfn[v]) dfs(v), low[u] = min(low[u], dfn[v]);
        else if (count(V.begin(), V.end(), v)) low[u] = min(low[u], dfn[v]);

    if (low[u] == dfn[u])
    {
        int temp;
        do 
        {
            temp = V[V.size() - 1];
            V.pop_back();
            com[temp] = cnt;
        } while (temp != u);
        ++cnt;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t, n, m, x, y;
    cin >> t;

    while (t--)
    {
        // init
        cin >> n >> m;
        G.assign(n + 1, vector<int>());
        low.assign(n + 1, 0);
        dfn.assign(n + 1, 0);
        com.assign(n + 1, 0);
        V.clear();
        dep = cnt = 0;

        // store data
        while (m--)
        {
            cin >> x >> y;
            G[x].emplace_back(y);
        }
        
        // find scc
        for (int i = 1; i <= n; ++i) if (!dfn[i]) dfs(i);

        // get result
        int result = 0;
        vector<int> conxt(cnt);

        for (int i = 1; i <= n; ++i) for (auto& j : G[i])
            if (com[i] != com[j]) ++conxt[com[j]];
        for (auto& i : conxt) if (!i) ++result;
        if (!result) ++result;

        cout << result << "\n";
    }

    return 0;
}