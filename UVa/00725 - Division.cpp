#include <iostream>
#include <sstream>
#include <algorithm>
#include <queue>
#define p pair<string, string> 

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	int N, cnt = 0;
	string s = "0123456789";

	while (cin >> N, N)
	{
		priority_queue<p, vector<p>, greater<p>> ans;

		for (int i = 98765; i >= 1234; --i) if (i % N == 0)
		{		
			int num = i / N;
			string str;
			string t1, t2;
			stringstream ss1, ss2;
				
			ss1 << i, ss1 >> t1;				
			ss2 << num, ss2 >> t2;
				
			str = t1 + t2;
			if (str.size() == 9) str += '0';
			sort(str.begin(), str.end());

			if (str == s) ans.push({ t1, t2});		
		}

		if (cnt++) cout << "\n";
		if (ans.empty()) cout << "There are no solutions for " << N << ".\n";
		else
		{
			while (!ans.empty())
			{
				auto& [i, j] = ans.top();
				cout << i << " / " << (j.size() == 4 ? "0" : "") << j << " = " << N << "\n";
				ans.pop();
			}
		}
	}

	return 0;
}