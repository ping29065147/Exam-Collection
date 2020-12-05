#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <queue>

using namespace std;

map<string, vector<string>> G;

int bfs(string s1, string s2)
{
    queue<string> Q;
    map<string, bool> vis;
    map<string, int> dis;

    Q.emplace(s1);
    vis[s1] = true;
    dis[s1] += 0;

    while (!Q.empty())
    {
        string u = Q.front();
        Q.pop();
        if (u == s2) break;

        for (auto& v : G[u]) if (!vis[v])
        {
            Q.emplace(v);
            dis[v] = dis[u] + 1;
            vis[v] = true;
        }
    }

    return dis[s2];
}

int main()
{
    // fast io
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<string> V;
    string str, s1, s2;
    int N;

    cin >> N;
    cin.ignore();
    getline(cin, str); // blank line

    while (N--)
    {
        V.clear();
        G.clear();

        // store data and build graph
        while (getline(cin, str), str != "*")
        {
            for (auto i : V)
            {
                int dif = 0;

                for (int j = 0; j < min(i.size(), str.size()); ++j) 
                    if (str[j] != i[j]) ++dif;          

                if (dif <= 1)
                {
                    G[i].emplace_back(str);
                    G[str].emplace_back(i);
                }
            }

            V.emplace_back(str);
        }

        // search for key and target
        while (getline(cin, str), str != "")
        {
            stringstream ss(str);
            ss >> s1 >> s2;

            cout << s1 << " " << s2 << " " << bfs(s1, s2) << "\n";
        }

        if (N) cout << "\n";
    }

    return 0;
}