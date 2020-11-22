#include <iostream>
#include <memory.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> graph[101], result;
bool check[101], link[101];

void dfs(int num)
{
	check[num] = true;
	for (auto& i : graph[num]) if (!check[i]) dfs(i);
	result.emplace_back(num);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	int a, b;

	while (cin >> n >> m && (n || m)) {

		fill(graph, graph + 101, vector<int>());
		memset(check, false, sizeof(check));
		memset(link, false, sizeof(link));
		result.clear();
		
		while (m--) {
			cin >> a >> b;
			graph[a].emplace_back(b);
			link[b] = true;
		}

		for (int i = 1; i <= n; ++i) if (!link[i]) dfs(i);

		for (int i = result.size() - 1; i >= 0; --i)
			cout << result[i] << (i != 0 ? " " : "\n");
	}

	return 0;
}