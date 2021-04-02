#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	int T, N, R, u, v;
	cin >> T;

	for (int cases = 1; cases <= T; ++cases)
	{
		cin >> N >> R;

		vector<vector<int>> G(N, vector<int>(N, 101));
		for (int i = 0; i < R; ++i)
		{
			cin >> u >> v;
			G[u][v] = 1;
			G[v][u] = 1;
		}
		for (int i = 0; i < N; ++i) G[i][i] = 0;

		// Floyd-Warshall algorithm
		for (int k = 0; k < N; ++k) for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j)
			G[i][j] = min(G[i][j], G[i][k] + G[k][j]);

		int Max = 0, s, d;
		cin >> s >> d;
		for (int i = 0; i < N; ++i) Max = max(Max, G[s][i] + G[i][d]);

		cout << "Case " << cases << ": " << Max << "\n";
	}

	return 0;
}