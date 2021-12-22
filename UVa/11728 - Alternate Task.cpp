#include <iostream>
#include <unordered_map>

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
	unordered_map<int, int> M;
	int N, cnt = 0;

	for (int i = 1; i <= 1000; ++i)
	{
		int sum = 0;
		
		for (int j = 1; j <= i; ++j) if (i % j == 0) sum += j;
		M[sum] = i;
	}

	while (cin >> N, N)
	{
		cout << "Case " << ++cnt << ": " << (M[N] ? M[N] : -1) << "\n";
	}
}