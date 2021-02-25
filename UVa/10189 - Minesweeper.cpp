#include <iostream>
#include <memory.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m, cases = 0;
	char ch;
	int G[102][102];

	while (cin >> n >> m, n && m)
	{
		memset(G, 0, sizeof(G));

		for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j)
		{
			cin >> ch;
			if (ch == '*')
			{
				G[i][j] -= 10;
				for (int x = i - 1; x <= i + 1; ++x) for (int y = j - 1; y <= j + 1; ++y)
				{
					++G[x][y];
				}
			}
		}

		cout << (cases ? "\n" : "") << "Field #" << ++cases << ":\n";
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
				G[i][j] >= 0 ? cout << G[i][j] : cout << "*";
			cout << "\n";
		}
	}

	return 0;
}