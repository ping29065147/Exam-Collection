#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
	// fast io
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, a, b, x;

	while (cin >> N, N)
	{
		// init
		vector<int> student;
		int maxn = 0;
		pair<int, int> minn = { INT_MAX, 1 };

		// store data
		cin >> a >> b;
		for (int i = 0; i < N; ++i)
		{
			cin >> x;
			student.emplace_back(x * 6);
			maxn = max(maxn, x * 6);
		}

		// run all posible of n
		for (int div = 1; div <= 3; ++div) for (auto& i : student)
		{
			int s1 = i / div;
			int x = 0, y = 0;

			if (s1 * 3 < maxn) continue;			

			for (auto& j : student)
			{
				int s2 = j;
				while (s1 - s2 < 0) s2 -= s1, ++y;
				x += (s1 - s2);
				++y;
			}

			minn = min(minn, { x * a + y * b * 6, div });
		}

		auto& [i, j] = minn;
		if (i % 6 == 0) cout << i / 6;
		else cout << i * j / 6 << " / " << j;
		cout << "\n";		
	}

	return 0;
}