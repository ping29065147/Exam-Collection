#include <iostream>
#include <math.h>

using namespace std;

static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

long long dfs(int  k, long long i)
{
	if (i == 0) return 0;
	if (k == 0) return 1;
	long long n = 1 << (k - 1);
	return (i >= n ? 2 * dfs(k - 1, i - n) + pow(3, k - 1) : dfs(k - 1, i));
}

int main()
{
	int t, k, a, b, Case = 0;
	cin >> t;

	while (t--)
	{
		cin >> k >> a >> b;
		long long n = 1 << k;
		cout << "Case " << ++Case << ": " << dfs(k, n - a + 1) - dfs(k, n - b) << "\n";
	}
}