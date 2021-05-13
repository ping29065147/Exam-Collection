#include <iostream>
#include <memory.h>
#include <climits>
#include <queue>
#include <vector>
#include <math.h>

using namespace std;

int T, N, x, y, n, m, sum;
float D;
int _s = 0, _t;
vector<vector<int>> G, cpy;
vector<int> p, ans;
vector<pair<int, int>> ice;
vector<bool> vis;

void fast_io()
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
}

void init()
{
	G.assign(250, vector<int>(250, 0));
	p.assign(250, 0);
	ice.assign(250, { 0, 0 });
	ans.clear();
	sum = 0;
}

bool canjump(int i, int j)
{
	auto& [x1, y1] = ice[i];
	auto& [x2, y2] = ice[j];

	if (D * D - pow(x2 - x1, 2) - pow(y2 - y1, 2) > 0) return true;
	return false;
}

void read_build()
{
	cin >> N >> D;
	_t = N * 2 + 1;

	for (int i = 1; i <= N; ++i)
	{
		cin >> x >> y >> n >> m;

		sum += n;
		ice[i] = { x, y };
		G[_s][i] = n;
		G[i][i + N] = m;
	}

	for (int i = 1; i <= N; ++i) for (int j = 1; j <= N; ++j)
		if (i != j && canjump(i, j)) G[i + N][j] = INT_MAX;

	cpy = G;
}

int findflow(int u, int v, int c)
{
	if (v == _s) return c;
	c = findflow(p[u], u, min(G[u][v], c));
	G[u][v] -= c;
	G[v][u] += c;
	return c;
}

int maxflow()
{
	int ret = 0;

	while (1)
	{
		vis.assign(250, false);

		queue<int> Q;
		Q.emplace(_s);
		vis[_s] = true;

		while (!Q.empty() && !vis[_t])
		{
			int u = Q.front();
			Q.pop();

			for (int i = _s; i <= _t; ++i) if (!vis[i] && G[u][i] > 0)
			{
				Q.emplace(i);
				vis[i] = true;
				p[i] = u;
			}
		}

		if (!vis[_t]) break;
		ret += findflow(p[_t], _t, INT_MAX);
	}

	return ret;
}

int main()
{
	fast_io();

	cin >> T;
	while (T--)
	{
		init();
		read_build();
		for (int i = 1; i <= N; ++i)
		{
			G = cpy;
			G[i][_t] = INT_MAX;
			if (maxflow() == sum) ans.emplace_back(i - 1);
			G[i][_t] = 0;
		}

		if (!ans.empty())
		{
			for (int i = 0; i < ans.size(); ++i)
			{
				if (i) cout << " ";
				cout << ans[i];
			}
			cout << "\n";
		}
		else cout << "-1\n";
	}
}