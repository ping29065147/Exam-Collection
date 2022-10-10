#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

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
	int s, cnt = 0;
    string n;
	unordered_map<char, vector<bool>> digits = {{'0',{1,1,1,0,1,1,1}},
												{'1',{0,0,1,0,0,1,0}},
												{'2',{1,0,1,1,1,0,1}},
												{'3',{1,0,1,1,0,1,1}},
												{'4',{0,1,1,1,0,1,0}},
												{'5',{1,1,0,1,0,1,1}},
												{'6',{1,1,0,1,1,1,1}},
												{'7',{1,0,1,0,0,1,0}},
												{'8',{1,1,1,1,1,1,1}},
												{'9',{1,1,1,1,0,1,1}}};

	while (cin >> s >> n, s || n != "0")
	{
		for (int i = 0; i < 7; ++i)
		{
			if (i == 2 || i == 5) ++i;

			if ((i == 0 || i == 3 || i == 6))
			{
				for (int x = 0; x < n.size(); ++x)
				{
					if (x) cout << ' ';
					cout << ' ';
					for (int j = 0; j < s; ++j) cout << (digits[n[x]][i] ? '-' : ' ');
					cout << ' ';
				}
			}
			else
			{
				for (int k = 0; k < s; ++k)
				{
					if (k) cout << "\n";
					for (int x = 0; x < n.size(); ++x)
					{
						if (x) cout << ' ';
						cout << (digits[n[x]][i] ? '|' : ' ');
						for (int j = 0; j < s; ++j) cout << ' ';
						cout << (digits[n[x]][i + 1] ? '|' : ' ');
					}
				}
			}

			cout << "\n";
		}
		cout << "\n";
	}
}