#include <iostream>
#include <vector>
#include <unordered_set>
#include <iomanip>
#include <climits>

using namespace std;

int main()
{
	// fast io
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	int u, v, cases = 0;
	vector<vector<int>> G(101);
	unordered_set<int> S;

	while (cin >> u >> v, u && v)
	{
		// init
		for (int i = 0; i < G.size(); ++i) G[i].assign(101, 101);
		S.clear();
		double ans = 0;
		int Max = 0;

		do
		{
			G[u][v] = 1;
			Max = max(Max, max(u, v));
			S.emplace(u);
			S.emplace(v);

		} while (cin >> u >> v, u && v);

		// Floyd-Warshall algorithm
		for (int k = 1; k <= Max; ++k) for (int i = 1; i <= Max; ++i) for (int j = 1; j <= Max; ++j)
			G[i][j] = min(G[i][j], G[i][k] + G[k][j]);

		int Size = S.size() * (S.size() - 1);
		for (auto i = S.begin(); i != S.end(); ++i) for (auto j = S.begin(); j != S.end(); ++j)
			if (*i != *j) ans += G[*i][*j];

		cout << "Case " << ++cases << ": average length between pages = " << setprecision(3) << fixed << ans / Size << " clicks\n";
	}

	return 0;
}