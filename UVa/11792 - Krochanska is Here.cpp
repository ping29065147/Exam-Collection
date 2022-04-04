#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

vector< vector<int> > G;
vector<int> cross;

int dijkstra(int root, int n)
{
	vector<int> dist(n + 1, INT_MAX);
	vector<bool> vis(n + 1, false);
	queue<int> Q;
	int cnt = 0;

	dist[root] = 0;
	Q.push(root);
	
	while (!Q.empty())
	{
		int u = Q.front(); Q.pop();

		for (auto& i : G[u])
		{
			if (dist[i] > dist[u] + 1)
			{
				dist[i] = dist[u] + 1;
				if (!vis[i]) vis[i] = true, Q.push(i);
			}
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		if (cross[i] <= 1) continue;
		cnt += dist[i];
	}

	return cnt;
}

int main()
{
	int t, n, m;
	cin >> t;

	while (t--)
	{
		cin >> n >> m;

		int v, u;
		int Min = INT_MAX, ret = 0;
		G.assign(n + 1, vector<int>());
		cross.assign(n + 1, 0);

		while (m--)
		{
			cin >> v;
			++cross[v];
			while (cin >> u, u)
			{
				G[v].push_back(u);
				G[u].push_back(v);
				++cross[u];
				v = u;
			}
		}

		for (int i = 1; i <= n; ++i)
		{
			if (cross[i] <= 1) continue;

			int cnt = dijkstra(i, n);
			if (cnt < Min) ret = i, Min = cnt;
		}

		cout << "Krochanska is in: " << ret << "\n";
	}
}