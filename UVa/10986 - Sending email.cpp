#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>

using namespace std;
typedef pair<int, int> p;

priority_queue<p, vector<p>, greater<p>> pq;
vector< vector<p> > edge;
int vals[20001];
bool vis[20001];

void dijkstra(int start)
{
	vals[start] = 0;
	pq.push({ 0, start });

	while (!pq.empty())
	{
		auto [val, u] = pq.top();
		pq.pop();
		vis[u] = true;

		for (auto& [v, w] : edge[u]) if (!vis[v])
		{
			int tmp = val + w;
			if (vals[v] == -1 || vals[v] > tmp)
			{
				vals[v] = tmp;
				pq.push({ tmp, v });
			}
		}
	}
}

int main()
{
	// fast io
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T, cases = 0;
	cin >> T;

	while (T--)
	{
		int n, m, s, t;
		cin >> n >> m >> s >> t;

		// init
		edge.assign(n, vector<p>());
		memset(vals, -1, sizeof(vals));
		memset(vis, false, sizeof(vis));

		// store data in both side
		while (m--)
		{
			int u, v, w;
			cin >> u >> v >> w;
			edge[u].push_back({ v, w });
			edge[v].push_back({ u, w });
		}

		// dijkstra algorithm
		dijkstra(s);

		cout << "Case #" << ++cases << ": ";
		if (vals[t] == -1) cout << "unreachable\n";
		else cout << vals[t] << "\n";
	}

	return 0;
}