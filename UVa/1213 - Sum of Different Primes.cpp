#include <iostream>
#include <vector>;

using namespace std;

int main()
{
	// fast io
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, K;
	vector<int> prime;
	vector<bool> vis(1121);
	int dp[1121][15] = {};

	// find prime number
	prime.emplace_back(2);
	for (int i = 3; i <= 1120; i += 2) if (!vis[i])
	{
		prime.emplace_back(i);
		for (int j = i * 2; j <= 1120; j += i) vis[j] = true;
	}

	// dp (knapsack)
	dp[0][0] = 1;
	for (int k = 0; k < prime.size(); ++k) for (int i = 1120; i >= prime[k]; --i)
		for (int j = 14; j >= 1; --j) dp[i][j] += dp[i - prime[k]][j - 1];

	while (cin >> N >> K, N && K) cout << dp[N][K] << "\n";

	return 0;
}