#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;

vector< vector<int> > G, bcc;
vector<int> dfn, low;
vector<bool> iscut;
stack< pair<int, int> > S;
int dep;

void dfs(int u, int par)
{
    int child = 0;
    dfn[u] = low[u] = ++dep;

    for (auto& v : G[u]) 
    {
        if (!dfn[v]) 
        {
            ++child;
            S.push({ u, v });

            dfs(v, u);
            low[u] = min(low[u], low[v]);

            if (low[v] >= dfn[u]) 
            {
                iscut[u] = true;
                vector<int> V;
                unordered_set<int> US;
                while(1)
                {
                    int cu = S.top().first, cv = S.top().second; S.pop();                 
                    US.emplace(cu), US.emplace(cv);
                    if (cu == u && cv == v) break;
                }
                for (auto it = US.begin(); it != US.end(); ++it) V.emplace_back(*it);
                bcc.emplace_back(V);
            }         
        }
        else if (dfn[v] < dfn[u] && v != par) low[u] = min(low[u], dfn[v]);
    }

    if (par == -1 && child == 1) iscut[u] = false;
}

int main()
{
    // fast io
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int N, cases = 0;
    while (cin >> N, N) 
    {
        // init
        G.assign(N + 2, vector<int>()), bcc.clear();
        dfn.assign(N + 2, 0), low.assign(N + 2, 0);
        iscut.assign(N + 2, false);
        dep = 0;

        // store data
        for (int i = 0, a, b; i < N; ++i) 
        {
            cin >> a >> b;
            G[a].emplace_back(b);
            G[b].emplace_back(a);
        }

        // find bcc and bcc's element
        dfs(1, -1);

        // solve
        long long ans1 = 0, ans2 = 1;
        if (bcc.size() == 1) ans1 = 2, ans2 = bcc[0].size() * (bcc[0].size() - 1) / 2;
        else for (auto& i : bcc)
        {
            int count = 0;
            for (auto& j : i) if (iscut[j]) ++count;
            if (count == 1) ++ans1, ans2 *= i.size() - 1;
        }

        cout << "Case " << ++cases << ": " << ans1 << " " << ans2 << "\n";
    }

    return 0;
}