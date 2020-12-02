#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> > G;
vector<bool> dfn;
vector<int> V;

void dfs(int u)
{
	dfn[u] = true;
	for (auto& v : G[u]) if (!dfn[v]) dfs(v);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t, n, m, x, y, result;
	cin >> t;

	while (t--)
	{
		cin >> n >> m;
		G.assign(n + 1, vector<int>());
		dfn.assign(n + 1, false);
		V.clear();
		result = 0;

		while (m--) cin >> x >> y, G[x].emplace_back(y);

		for (int u = 1; u <= n; ++u) if (!dfn[u])
			dfs(u), V.emplace_back(u);

		dfn.assign(n + 1, false);
		for (int u = V.size() - 1; u >= 0; --u) if (!dfn[V[u]])
			dfs(V[u]), ++result;

		cout << result << "\n";
	}

	return 0;
}