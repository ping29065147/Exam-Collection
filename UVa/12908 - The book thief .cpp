#include <iostream>

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
	int n;

	while (cin >> n, n)
	{
		int i = 0, sum = 0;
		while (sum <= n) sum += ++i;
		cout << sum - n << " " << i << "\n";
	}
}