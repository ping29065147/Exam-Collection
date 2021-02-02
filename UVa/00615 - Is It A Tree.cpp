#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<int, vector<int>> G;
map<int, int> vis;
int root;

void dfs(int p, int u)
{
	++vis[u];

	for (auto& v : G[u]) if (v != p)
	{
		if (!vis[v]) dfs(u, v);
		else ++root;

		if (root > 1) return;
	}
}

int main()
{
	// fast io
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int u, v, cases = 0;	

	while (cin >> u >> v, u >= 0)
	{
		// init
		G.clear();
		vis.clear();
		root = 0;

		while (u)
		{
			G[u].emplace_back(v);
			G[v].emplace_back(u);
			cin >> u >> v;
		}

		for (auto& [u, v] : G) if (!vis[u])
		{
			++root;
			dfs(-1, u);
		}

		cout << "Case " << ++cases << " is" << (root < 2 ? "" : " not") << " a tree.\n";
	}

	return 0;
}