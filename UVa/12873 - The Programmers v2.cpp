#include <iostream>
#include <queue>
#include <memory.h>
#include <climits>

using namespace std;

static auto fats_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

int T, P, S, C, M, u, v;
int _s = 0, _t;
int G[550][550];
int p[550];
bool vis[550];

void init()
{
	memset(G, 0, sizeof(G));
	memset(p, 0, sizeof(p));
}

void read()
{
	cin >> P >> S >> C >> M;

	_t = P + S + 1;
	while (M--)
	{
		cin >> u >> v;
		G[u][P + v] = 1;
	}
	for (int i = 1; i <= P; ++i) G[_s][i] = 1;
	for (int i = P + 1; i <= P + S; ++i) G[i][_t] = C;
}

int updateflow(int u, int v, int c)
{
	if (v == _s) return c;
	c = updateflow(p[u], u, min(G[u][v], c));
	G[u][v] -= c;
	G[v][u] += c;
	return c;
}

int maxflow()
{
	int ret = 0;

	while (1)
	{
		memset(vis, false, sizeof(vis));
		queue<int> Q;
		Q.emplace(_s);
		vis[_s] = true;

		while (!Q.empty() && !vis[_t])
		{
			int u = Q.front();
			Q.pop();

			for (int v = _s; v <= _t; ++v) if (!vis[v] && G[u][v] > 0)
			{
				Q.emplace(v);
				vis[v] = true;
				p[v] = u;
			}
		}

		if (!vis[_t]) break;
		ret += updateflow(p[_t], _t, INT_MAX);
	}

	return ret;
}

int main()
{
	cin >> T;

	while (T--)
	{
		init();
		read();
		cout << maxflow() << "\n";
	}
}