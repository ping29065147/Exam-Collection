#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string str;

	while (cin >> str)
	{
		for (auto& c : str)
		{
			if (c >= 'A' && c <= 'C') cout << 2;
			else if (c >= 'D' && c <= 'F') cout << 3;
			else if (c >= 'G' && c <= 'I') cout << 4;
			else if (c >= 'J' && c <= 'L') cout << 5;
			else if (c >= 'M' && c <= 'O') cout << 6;
			else if (c >= 'P' && c <= 'S') cout << 7;
			else if (c >= 'T' && c <= 'V') cout << 8;
			else if (c >= 'W' && c <= 'Z') cout << 9;
			else cout << c;
		}
		cout << "\n";
	}

	return 0;
}