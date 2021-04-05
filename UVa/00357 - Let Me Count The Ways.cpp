#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	int N;
	long long coin[30001]{};
	int dif[] = { 1, 5, 10, 25, 50 };

	coin[0] = 1;
	for (auto& j : dif) for (int i = j; i <= 30000; ++i) coin[i] += coin[i - j];

	while (cin >> N)
	{
		if (coin[N] == 1) cout << "There is only 1 way to produce " << N << " cents change.\n";
		else cout << "There are " << coin[N] << " ways to produce " << N << " cents change.\n";
	}

	return 0;
}