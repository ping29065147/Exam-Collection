#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_set>
#include <algorithm>

using namespace std;

vector<bool> is_prime;
unordered_set<int> result;

void find_prime()
{
	is_prime.assign(10000000, true);
	is_prime[0] = is_prime[1] = false;

	for (int i = 2; i < 10000000; ++i)
	{
		if (is_prime[i])
		{
			for (int j = i << 1; j < 10000000; j += i) is_prime[j] = false;
		}
	}
}

void dfs(string str, string target, int now, int Max)
{
	if (now == Max)
	{
		stringstream ss(target);
		int tmp;

		ss >> tmp;
		result.emplace(tmp);

		return;
	}

	for (size_t i = 0; i < str.size(); ++i)
	{
		auto s = str;
		s.erase(s.begin() + i);
		dfs(s, target + str[i], now + 1, Max);
	}
}

int main()
{
	// fast io
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	// find all prime number between 1 ~ 10000000
	find_prime();

	int N;
	string str;
	cin >> N;

	while (N-- && cin >> str)
	{
		result.clear();		
		int cnt = 0;

		// use dfs to find all permutation of str
		for (size_t i = 1; i <= str.size(); ++i) dfs(str, "", 0, i);
		for (auto& i : result) if (is_prime[i]) ++cnt;

		cout << cnt << "\n";
	}

	return 0;
}