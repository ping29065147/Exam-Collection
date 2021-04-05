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

	int N, M, S, a, b;
	cin >> N;

	while (N-- && cin >> M >> S)
	{
		// init
		vector<vector<int>> dp(301, vector<int>(301, INT_MAX / 2));
		vector<pair<int, int>> coin(M);
		dp[0][0] = 0;
		S *= S;

		for (int i = 0; i < M; ++i) cin >> a >> b, coin.push_back({ a, b });

		for (auto& [con, info] : coin)
		{
			for (int i = con; i <= 300; ++i) for (int j = info; j <= 300; ++j)
				dp[i][j] = min(dp[i][j], dp[i - con][j - info] + 1);
		}

		// find e-modulus
		int ans = INT_MAX / 2;
		for (int i = 0; i <= 300; ++i) for (int j = 0; j <= 300; ++j)
			if (i * i + j * j == S) ans = min(ans, dp[i][j]);
		
		if (ans == INT_MAX / 2) cout << "not possible\n";
		else cout << ans << "\n";
	}

	return 0;
}