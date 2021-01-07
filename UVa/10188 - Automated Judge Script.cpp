#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M, cases = 0;
	string tmp;

	while (cin >> N, N)
	{
		vector<string> ans, team;

		cin.ignore();
		while (N--)
		{
			getline(cin, tmp);
			ans.emplace_back(tmp);
		}

		cin >> M;
		cin.ignore();
		while (M--)
		{
			getline(cin, tmp);
			team.emplace_back(tmp);
		}

		cout << "Run #" << ++cases << ": ";
		if (ans == team)
		{
			cout << "Accepted\n";
			continue;
		}
		
		string ans_num, team_num;

		for (auto& i : ans) for (auto& j : i)
		{
			if (j >= '0' && j <= '9') ans_num.push_back(j);
		}

		for (auto& i : team) for (auto& j : i)
		{
			if (j >= '0' && j <= '9') team_num.push_back(j);
		}

		if (ans_num == team_num) cout << "Presentation Error\n";
		else cout << "Wrong Answer\n";
	}

	return 0;
}