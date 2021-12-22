#include <iostream>
#include <string>
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
	int T, cnt = 0;
	string str;

	cin >> T;

	while (T--)
	{
		cin >> str;

		int len = 0, tmp = 0;
		for (auto& c : str)
		{
			if (c == 'R') ++tmp;
			else if (c == 'F') --tmp;
			len = max(len, max(tmp, -tmp));
		}

		vector<vector<char>> V(len * 2 + 1, vector<char>(str.size() + 1, ' '));

		int x = len, y = 0;
		for (auto& c : str)
		{
			if (c == 'R') V[x++][y++] = '/';
			else if (c == 'F') V[--x][y++] = '\\';
			else V[x][y++] = '_';
		}

		cout << "Case #" << ++cnt << ":\n";
		for (int i = V.size() - 1; i >= 0; --i)
		{
			while (!V[i].empty())
			{
				if (V[i].back() == ' ') V[i].pop_back();
				else break;
			}
			if (!V[i].empty())
			{
				cout << "| ";
				for (auto& j : V[i]) cout << j;
				cout << "\n";
			}
		}
		cout << "+";
		for (int i = 0; i < str.size() + 2; ++i) cout << '-';
		cout << "\n\n";
	}
}