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
	int t, n, m, a, b, Case = 0;
	string str;
	cin >> t;

	while (t--)
	{
		cin >> n;
		vector<vector<int>> V(n, vector<int>(n));
		for (int i = 0, tmp; i < n; ++i)
		{
			cin >> tmp;
			for (int j = n - 1; j >= 0; --j)
			{
				V[i][j] = tmp % 10;
				tmp /= 10;
			}
		}
		cin >> m;

		while (m--)
		{
			cin >> str;

			if (str == "row")
			{
				cin >> a >> b;
				for (int i = 0; i < n; ++i)
					swap(V[a - 1][i], V[b - 1][i]);
			}
			else if (str == "col")
			{
				cin >> a >> b;
				for (int i = 0; i < n; ++i)
					swap(V[i][a - 1], V[i][b - 1]);
			}
			else if (str == "inc")
				for (int i = 0; i < n; ++i)
					for (int j = 0; j < n; ++j)
						V[i][j] = (V[i][j] + 1) % 10;
			else if (str == "dec")
				for (int i = 0; i < n; ++i)
					for (int j = 0; j < n; ++j)
						V[i][j] = (V[i][j] + 9) % 10;
			else
				for (int i = 0; i < n; ++i)
					for (int j = i + 1; j < n; ++j)
						swap(V[i][j], V[j][i]);
		}

		cout << "Case #" << ++Case << "\n";
		for (auto& i : V)
		{
			for (auto& j : i) cout << j;
			cout << "\n";
		}
		cout << "\n";
	}
}