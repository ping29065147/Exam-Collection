#include <iostream>
#include <vector>

using namespace std;

static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

int main()
{
	vector<int> coin = { 1, 5, 10, 25, 50 };
	vector<int> W(7500, 1);
	int n;

	for (int i = 1; i < coin.size(); ++i)
		for (int j = 0; j <= 7489 - coin[i]; ++j)
			W[j + coin[i]] += W[j];

	while (cin >> n) cout << W[n] << "\n";
}