#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	int T, price, N;
	cin >> T;

	while (T-- && cin >> price >> N)
	{
		vector<int> dp(20001, INT_MAX / 2);
		vector<int> coin(N);
		int sum = 0;
		dp[0] = 0;

		for (int i = 0; i < N; ++i)
		{
			cin >> coin[i];
			if (sum < price) sum += coin[i];
		}

		for (int i = 0; i < N; ++i) for (int j = sum; j >= coin[i]; --j) 
			dp[j] = min(dp[j], dp[j - coin[i]] + 1);
		
		while (dp[price] == INT_MAX / 2) ++price;

		cout << price << " " << dp[price] << "\n";
	}

	return 0;
}