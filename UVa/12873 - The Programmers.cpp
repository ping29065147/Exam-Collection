#include <iostream>
#include <memory.h>

using namespace std;

// connected graph: S -> teams -> sites -> T
int T, P, S, C, m;
int _s = 0, _t;
int u, v;
int G[530][530];
bool vis[530];

void fast_io()
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
}

void init()
{
	memset(G, 0, sizeof(G));
}

void read()
{
	cin >> P >> S >> C >> m;

	_t = P + S + 1;

	for (int i = 0; i < m; ++i)
	{
		cin >> u >> v;
		G[u][v + P] = 1; // connect teams to sites
	}	
	for (int i = 1; i <= P; ++i) G[_s][i] = 1; // connect S to teams
	for (int i = P + 1; i < _t; ++i) G[i][_t] = C; // connect sites to T
}

bool dfs(int u, int v)
{
	vis[u] = true;
	if (u == v) return true;

	for (int i = 0; i <= _t; ++i)
	{
		if (G[u][i] > 0 && !vis[i] && dfs(i, v))
		{
			--G[u][i];
			++G[i][u];
			return true;
		}
	}

	return false;
}

int maxflow()
{
	int ret = 0;

	while (1)
	{
		memset(vis, false, sizeof(vis));
		if (dfs(_s, _t)) ++ret;
		else break;
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
		read();
		cout << maxflow() << "\n";
	}
}