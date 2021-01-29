#include <iostream>

using namespace std;

int main()
{
	// fast io
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string str;
	int n, m;

	while (cin >> str >> n >> m)
	{
		int _10 = 0;
		string ans;

		// turn the base n to decimal		
		for (int i = str.size() - 1, div = 1; i >= 0; --i, div *= n)
		{
			if (str[i] <= '9') _10 += (str[i] - '0') * div;
			else _10 += (str[i] - 'A' + 10) * div;
		}

		// turn decimal to base m
		while (_10 > 0)
		{
			if (_10 % m < 10) ans.push_back(_10 % m + '0');
			else ans.push_back(_10 % m -10 + 'A');
			_10 /= m;
		}

		if (ans.size() > 7) cout << "  ERROR";
		else
		{
			if (ans.empty()) ans.push_back('0');
			int sp = 7 - ans.size();
			while (sp-- != 0) cout << " ";
			for (int i = ans.size() - 1; i >= 0; --i) cout << ans[i];
		}
		cout << "\n";
	}

	return 0;
}