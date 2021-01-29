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
		for (auto& c : str) cout << (char)(c - 7);
		cout << "\n";
	}

	return 0;
}