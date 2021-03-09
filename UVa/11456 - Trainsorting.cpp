#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int S, N, a, ans;
	vector<int> train;
	vector<int> len;

	cin >> S;

	while (S-- && cin >> N)
	{
		train.assign(N * 2, 0);
		len.assign(N * 2, 1);
		ans = 0;

		for (int i = 0; i < N; ++i)
		{
			cin >> a;
			train[N + i] = train[N - i - 1] = a;
		}
	
		for (int i = 0; i < N * 2; ++i) for (int j = 0; j < i; ++j)
		{
			if (train[i] > train[j]) len[i] = max(len[i], len[j] + 1);
			ans = max(ans, len[i]);
		}

		cout << ans << "\n";
	}

	return 0;
}