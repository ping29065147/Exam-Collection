#include <iostream>
#include <memory.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// connected graph: S -> teams -> words -> alphabet -> T
int T, N, K;
int STW; // size of S + teams + words
int _T; // size except T
string str;
vector<string> node;
vector<string> ret;
int G[710][710];
bool vis[710];

void fast_io()
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
}

void init()
{
	memset(G, 0, sizeof(G));
	node.clear();
	ret.clear();
}

void build()
{
	STW = node.size();
	for (char i = 'A'; i <= 'Z'; ++i) node.emplace_back(string(1, i)); // build node(alphabet)

	_T = node.size();
	node.emplace_back("_T"); // build node(T)

	for (int i = STW; i < _T; ++i) G[i][_T] = 1; // connect alphabet to T
	for (int i = N + 1; i < STW; ++i)
	{
		if (node[i][0] - 'A' < N)
			G[i][node[i][0] - 'A' + STW] = 1; // connect words to alphabet
	}
}

void read()
{
	cin >> N;
	node.emplace_back("_S"); // build node(S)
	for (int i = 0; i < N; ++i) node.emplace_back("_N"); // build node(teams)

	for (int i = 1; i <= N; ++i)
	{
		cin >> K;
		for (int j = 0; j < K; ++j)
		{
			cin >> str;
			for (auto& c : str) c = tolower(c);
			str[0] = toupper(str[0]);

			G[i][node.size()] = 1; // connect teams to words
			node.emplace_back(str); // build node(words)
		}

		G[0][i] = 1; // connect S to teams
	}

	build();
}

bool dfs(int u, int v, int c)
{
	vis[u] = true;
	if (u == v) return true;

	for (int i = 0; i < node.size(); ++i) if (G[u][i] > 0 && !vis[i] && dfs(i, v, c))
	{
		--G[u][i];
		++G[i][u];
		return true;
	}

	return false;
}

void maxflow()
{
	while (1)
	{
		memset(vis, false, sizeof(vis));
		if (!dfs(0, node.size() - 1, 1)) break;
	}
}

// check if teams to words is connected or not
void result()
{
	for (int j = N + 1; j < STW; ++j) for (int i = 1; i <= N; ++i)
	{
		if (!G[i][j] && G[j][i])
		{
			ret.emplace_back(node[j]);
			break;
		}
	}
	sort(ret.begin(), ret.end());
}

int main()
{
	fast_io();

	cin >> T;
	for (int Case = 1; Case <= T; ++Case)
	{
		init();
		read();
		maxflow();
		result();

		cout << "Case #" << Case << ":\n";
		for (auto& s : ret) cout << s << "\n";
	}
}