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
	int t, m, y, c;
	string s;
	cin >> t;

	while (t--)
	{
		cin >> m >> y >> c >> s;

		for (auto& i : s)
		{
			if (i == 'M') --m;
			else if (i == 'Y') --y;
			else if (i == 'C') --c;
			else if (i == 'R') --m, --y;
			else if (i == 'V') --m, --c;
			else if (i == 'G') --y, --c;
			else if (i == 'B') --m, --y, --c;
		}

		if (m >= 0 && y >= 0 && c >= 0) cout << "YES " << m << " " << y << " " << c << "\n";
		else cout << "NO\n";
	}
}