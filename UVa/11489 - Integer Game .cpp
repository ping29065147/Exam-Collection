#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	string N;
	cin >> T;

	for (int cases = 1; cases <= T; ++cases) 
	{
		bool s_win = false;
		vector<int> num;

		cin >> N;
		for (auto& c : N) num.emplace_back(c - '0');
		
		while (1)
		{
			int sum = 0;
			for (auto& i : num) sum += i;

			int i = 0;
			for (; i < num.size(); ++i) if ((sum - num[i]) % 3 == 0)
			{	
				s_win ^= 1;
				num.erase(num.begin() + i);
				break;
			}

			if (num.size() == 1)
			{
				s_win ^= 1;
				break;
			}

			if (i == num.size()) break;
		}

		cout << "Case " << cases << ": " << (s_win ? "S" : "T") << "\n";
	}

	return 0;
}