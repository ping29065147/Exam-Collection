#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <climits>
#include <algorithm>

using namespace std;

static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

int T, N, K;
string str;
int _s = 0, _t;
int G[710][710];
int P[710];
bool vis[710];
vector<string> ans;
vector<string> words;

void init()
{
	memset(G, 0, sizeof(G));
	memset(P, 0, sizeof(P));
	ans.clear();
	words.clear();
}

void read()
{
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		G[_s][i] = 1;
		cin >> K;

		for (int j = 0; j < K; ++j)
		{
			cin >> str;
			for (auto& c : str) c = tolower(c);
			str[0] = toupper(str[0]);
			
			words.emplace_back(str);
			G[i][words.size() + N] = 1;
		}
	}

	_t = words.size() + N + 27;
	for (int i = 1; i <= words.size(); ++i) G[N + i][words.size() + N + (words[i - 1][0] - 'A') + 1] = 1;
	for (int i = 1; i <= 26; ++i) G[words.size() + N + i][_t] = 1;
}

int updateflow(int u, int v, int c)
{
	if (v == _s) return c;
	c = updateflow(P[u], u, min(G[u][v], c));
	G[u][v] -= c;
	G[v][u] += c;
	return c;
}

void maxflow()
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
				P[v] = u;
				vis[v] = true;
			}
		}

		if (!vis[_t]) break;
		ret += updateflow(P[_t], _t, INT_MAX);
	}

	for (int j = 1; j <= words.size(); ++j) for (int i = 1; i <= N; ++i)
	{
		if (!G[i][N + j] && G[N + j][i])
		{
			ans.emplace_back(words[j - 1]);
			break;
		}
	}

	sort(ans.begin(), ans.end());
}

int main()
{
	cin >> T;

	for (int Case = 1; Case <= T; ++Case)
	{
		init();
		read();
		maxflow();

		cout << "Case #" << Case << ":\n";
		for (auto& s : ans) cout << s << "\n";
	}
}