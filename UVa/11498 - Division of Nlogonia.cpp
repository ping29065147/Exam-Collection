#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int k, n, m, x, y;

	while (cin >> k, k)
	{
		cin >> n >> m;

		while (k--)
		{
			cin >> x >> y;

			if (x == n || y == m) cout << "divisa\n";
			else if (x > n && y > m) cout << "NE\n";
			else if (x > n && y < m) cout << "SE\n";
			else if (y > m) cout << "NO\n";
			else cout << "SO\n";
		}
	}

	return 0;
}