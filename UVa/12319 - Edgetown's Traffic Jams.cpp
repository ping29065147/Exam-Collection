#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
	// fast io
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, v, u, a, b;
	string str;
	vector<int> g1[101], g2[101];

	while (cin >> N, N)
	{
		// init
		cin.ignore();
		for (int i = 1; i <= N; ++i)
		{
			g1[i].assign(N + 1, 101);
			g2[i].assign(N + 1, 101);
		}

		// store graph
		for (int i = 1; i <= N * 2; ++i)
		{
			getline(cin, str);
			stringstream ss(str);
			ss >> u;
			while (ss >> v) i <= N ? g1[u][v] = 1 : g2[u][v] = 1;
		}
		

		// Floyd-Warshall algorithm
		for (int k = 1; k <= N; ++k)
		{
			for (int i = 1; i <= N; ++i) for (int j = 1; j <= N; ++j)
			{
				g1[i][j] = min(g1[i][j], g1[i][k] + g1[k][j]);
				g2[i][j] = min(g2[i][j], g2[i][k] + g2[k][j]);
			}
		}

		cin >> a >> b;
		bool out = false;
		for (int i = 1; i <= N && !out; ++i) for (int j = 1; j <= N && !out; ++j)
		{
			if (i == j) continue;
			if (g2[i][j] > g1[i][j] * a + b) out = true;
		}

		cout << (out ? "No" : "Yes") << "\n";
	}

	return 0;
}