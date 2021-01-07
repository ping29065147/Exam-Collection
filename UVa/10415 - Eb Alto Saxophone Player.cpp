#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main()
{
	// fast io
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	vector<bool> finger;
	vector<int> count;
	map<char, string> notes;
	string str, cur;

	// init map
	notes['c']= "0111001111";
	notes['d']= "0111001110";
	notes['e'] = "0111001100";
	notes['f'] = "0111001000";
	notes['g'] = "0111000000";
	notes['a'] = "0110000000";
	notes['b'] = "0100000000";
	notes['C'] = "0010000000";
	notes['D'] = "1111001110";
	notes['E'] = "1111001100";
	notes['F'] = "1111001000";
	notes['G'] = "1111000000";
	notes['A'] = "1110000000";
	notes['B'] = "1100000000";

	cin >> T;
	cin.ignore();

	while (T--)
	{
		// init
		finger.assign(10, false);
		count.assign(10, 0);
		cur = "0000000000";

		getline(cin, str);

		for (auto& ch : str)
		{
			for (int i = 0; i < 10; ++i)
			{
				if (cur[i] == '0' && notes[ch][i] == '1') ++count[i];
			}
			cur = notes[ch];
		}

		for (int i = 0; i < 10; ++i)
		{
			if (i) cout << " ";
			cout << count[i];
		}
		cout << "\n";
	}

	return 0;
}