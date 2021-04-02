#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() 
{
	// fast io
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	int N, w, U, V, Y, M, tmp;
	char age, connect, u, v, y, m;
	vector< vector<int> > G[2];

	while (cin >> N, N)
	{
		// init
		G[0].assign(26, vector<int>());
		G[1].assign(26, vector<int>());
		for (int i = 0; i < 26; ++i) G[0][i].assign(26, 501), G[1][i].assign(26, 501);
		int Max = 0;
		int ans = 501;

		// store data in target graph
		for (int i = 0; i < N; ++i)
		{
			cin >> age >> connect >> u >> v >> w;
			U = u - 'A';
			V = v - 'A';

			if (age == 'Y') tmp = 0;
			else tmp = 1;

			G[tmp][U][V] = w;
			if (connect == 'B') G[tmp][V][U] = w;
			
			Max = max(Max, max(U, V));
		}
		for (int i = 0; i < 26; ++i) G[0][i][i] = G[1][i][i] = 0;

		// Floyd-Warshall algorithm
		for (int k = 0; k <= Max; ++k) for (int i = 0; i <= Max; ++i) for (int j = 0; j <= Max; ++j)
		{
			G[0][i][j] = min(G[0][i][j], G[0][i][k] + G[0][k][j]);
			G[1][i][j] = min(G[1][i][j], G[1][i][k] + G[1][k][j]);
		}

		cin >> y >> m;
		Y = y - 'A';
		M = m - 'A';

		for (int i = 0; i <= Max; ++i) ans = min(ans, G[0][Y][i] + G[1][M][i]);
		
		if (ans == 501) cout << "You will never meet.\n";
		else
		{
			cout << ans;
			for (int i = 0; i <= Max; ++i) if (ans == G[0][Y][i] + G[1][M][i]) cout << " " << char(i + 'A');
			cout << "\n";
		}
	}

	return 0;
}