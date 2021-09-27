#include <iostream>
#include <queue>
#include <climits>
#include <memory.h>

using namespace std;

static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

int N, S, T, C;
int cases = 0;
int G[105][105];
int P[105];
bool vis[105];

void init()
{
	memset(G, 0, sizeof(G));
	memset(P, 0, sizeof(P));
}

void read()
{
	int u, v, c;
	cin >> S >> T >> C;

	for (int i = 0; i < C; ++i)
	{
		cin >> u >> v >> c;
		G[u][v] += c;
		G[v][u] += c;
	}
}

int updateflow(int u, int v, int c)
{
	if (v == S) return c;
	c = updateflow(P[u], u, min(G[u][v], c));
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
		Q.emplace(S);
		vis[S] = true;

		while (!Q.empty() && !vis[T])
		{
			int u = Q.front();
			Q.pop();

			for (int v = 1; v <= N; ++v) if (!vis[v] && G[u][v] > 0)
			{
				Q.emplace(v);
				vis[v] = true;
				P[v] = u;
			}
		}

		if (!vis[T]) break;
		ret += updateflow(P[T], T, INT_MAX);
	}

	return ret;
}

int main()
{
	while (cin >> N, N)
	{
		init();
		read();
		cout << "Network " << ++cases << "\nThe bandwidth is " << maxflow() << ".\n\n";
	}
}