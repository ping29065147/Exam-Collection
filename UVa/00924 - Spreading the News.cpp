#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector< vector<int> > G;
vector<bool> vis;
vector<int> dep;
vector<int> day;

void bfs(int st)
{
	queue<int> Q;
		
	Q.emplace(st);
	vis[st] = true;
	dep[st] = 0;

	while (!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		
		for (auto& v : G[u]) if (!vis[v])
		{
			vis[v] = true;
			Q.emplace(v);
			dep[v] = dep[u] + 1;
			++day[dep[v]];
		}
	}

	pair<int, int> max;
	for (int i = 1; i < day.size(); ++i)
	{
		if (day[i] > max.first)
		{
			max.first = day[i];
			max.second = i;
		}
	}

	cout << max.first;
	if (max.first) cout << ' ' << max.second;
	cout << "\n";
}

int main()
{
	// fast io
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int E, T, st;
	cin >> E;

	G.assign(E, vector<int>());

	// store friend's data
	for (int i = 0, N, u; i < E; ++i)
	{
		cin >> N;
		while (N--) cin >> u, G[i].emplace_back(u);
	}

	cin >> T;
	while (T--)
	{
		vis.assign(E + 1, false);
		dep.assign(E + 1, 0);
		day.assign(E + 1, 0);

		cin >> st;
		bfs(st);
	}

	return 0;
}