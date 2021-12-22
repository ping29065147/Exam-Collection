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
	int T, N, a;

	cin >> T;

	while (T--)
	{
		vector<int> V;
		int cnt = 0;

		cin >> N;
		while (N--) cin >> a, V.push_back(a);

		for (int i = 1; i < V.size(); ++i) 
			for (int j = 0; j < i; ++j)
				if (V[i] >= V[j]) ++cnt;

		cout << cnt << "\n";
	}
}