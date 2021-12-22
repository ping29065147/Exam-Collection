#include <iostream>
#include <vector>
#include <climits>

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
	int T, N, a;

	cin >> T;

	while (T--)
	{
		vector<int> V;
		int Max = INT_MIN;

		cin >> N;
		while (N--) cin >> a, V.push_back(a);

		int num = V[0];
		for (int i = 1; i < V.size(); ++i)
		{
			Max = max(Max, num - V[i]);
			num = max(num, V[i]);
		}

		cout << Max << "\n";
	}
}