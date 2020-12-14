#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>

using namespace std;
typedef pair<int, int> p;

vector< vector<p> > edge;
priority_queue<p, vector<p>, greater<p>> pq;
int vals[101];
int vis[101];

void dijkstra(int End)
{
	vals[End] = 0;
	pq.push({ 0, End });

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

	int T;
	cin >> T;

	while (T--)
	{
		int N, End, Time, M;
		cin >> N >> End >> Time >> M;

		// init
		edge.assign(N + 1, vector<p>());
		memset(vis, false, sizeof(vis));
		for (int i = 0; i < 101; ++i) vals[i] = Time + 1;

		while (M--)
		{
			int u, v, w;
			cin >> u >> v >> w;
			edge[v].push_back({ u, w });
		}

		// dijkstra algorithm
		dijkstra(End);

		int count = 0;
		for (int i = 1; i <= N; ++i) if (vals[i] <= Time) ++count;

		cout << count << "\n";
		if (T) cout << "\n";
	}

	return 0;
}