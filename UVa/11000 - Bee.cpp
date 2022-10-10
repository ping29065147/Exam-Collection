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
	vector<pair<long long, long long>> bee(100, {1, 0});
	int n;

	for (int i = 1; i < 100; ++i)
	{
		bee[i].first = bee[i - 1].second + 1;
		bee[i].second = bee[i - 1].first + bee[i - 1].second;
	}

	while (cin >> n, n != -1) cout << bee[n].second << " " << bee[n].first + bee[n].second << "\n";
}