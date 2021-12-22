#include <iostream>
#include <string>
#include <unordered_map>
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
	unordered_map<char, int> CI = { {'N', 0}, {'E', 1}, {'S', 2}, {'W', 3} };
	unordered_map<int, char> IC = { {0, 'N'}, {1, 'E'}, {2, 'S'}, {3, 'W'} };
	unordered_map<int, pair<int, int>> M = { {0, {0, 1}}, {1, {1, 0}}, {2, {0, -1}}, {3, {-1, 0}} };
	vector<pair<int, int>> drop;
	int x, y, a, b, pos;
	char p;
	string str;

	cin >> x >> y;

	while (cin >> a >> b >> p && cin >> str)
	{
		bool lost = false;
		pos = CI[p];

		for (auto& c : str)
		{
			if (c == 'R') pos = (pos + 1) % 4;
			else if (c == 'L') pos = (pos + 3) % 4;
			else
			{
				int new_a = a + M[pos].first;
				int new_b = b + M[pos].second;

				if (new_a < 0 || new_a > x || new_b < 0 || new_b > y)
				{
					lost = true;
					for (auto& [i, j] : drop) if (a == i && b == j) lost = false;
					if (lost) drop.push_back({ a, b });					
				}		
				else a = new_a, b = new_b;
			}

			if (lost) break;
		}

		cout << a << " " << b << " " << IC[pos] << (lost ? " LOST\n" : "\n");
	}
}