#include <iostream>
#include <vector>
#include <queue>
#define p pair<int, int>

using namespace std;

vector< vector<int> > graph;
vector<int> dfn, low;
priority_queue<p, vector<p>, greater<p>> result;
int dep;

void dfs(int cur, int par)
{
	dfn[cur] = low[cur] = ++dep;

	for (auto& i : graph[cur]) {

		if (!dfn[i]) {
			dfs(i, cur);
			low[cur] = min(low[cur], low[i]);
		}
		else if (i != par) low[cur] = min(low[cur], dfn[i]);

		p tmp = { min(i, cur), max(i, cur) };
		if (low[i] > dfn[cur]) result.emplace(tmp);
	}
}

int main()
{
	int N;

	while (cin >> N) {

		graph.assign(N, vector<int>());
		dfn.assign(N, 0);
		low.assign(N, 0);
		dep = 0;

		for (int i = 0, a, b, n; i < N; ++i) {

			char tmp;
			cin >> a >> tmp >> n >> tmp;
			while (n--) cin >> b, graph[a].emplace_back(b);
		}

		for (int i = 0; i < N; ++i) if (!dfn[i]) dfs(i, -1);

		cout << result.size() << " critical links\n";
		while (!result.empty()) {
			cout << result.top().first << " - " << result.top().second << "\n";
			result.pop();
		}
		cout << "\n";
	}

	return 0;
}