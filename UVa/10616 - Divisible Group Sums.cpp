#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, Q, D, M;
	int a, cases = 0;
	long long dp[201][11];

	while (cin >> N >> Q, N && Q)
	{
		vector<int> num;
		while (N--) cin >> a, num.emplace_back(a);

		cout << "SET " << ++cases << ":\n";

		for (int i = 1; i <= Q; ++i)
		{
			cin >> D >> M;

			vector<int> num2;
			long long ans = 0;
			memset(dp, 0, sizeof(dp));

			for (auto& j : num) num2.emplace_back(j % D > 0 ? j % D : j % D + D);

			dp[0][0] = 1;
			for (int f = 0; f < num2.size(); ++f) for (int j = 200; j >= num2[f]; --j)
				for (int k = M; k > 0; --k) dp[j][k] += dp[j - num2[f]][k - 1];

			for (int j = 0; j <= 200; j += D) ans += dp[j][M];
			cout << "QUERY " << i << ": " << ans << "\n";
		}
	}

	return 0;
}