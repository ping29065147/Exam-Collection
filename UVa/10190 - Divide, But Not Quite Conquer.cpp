#include <iostream>
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
	int n, m;

	while (cin >> n >> m)
	{
		if (n <= 1 || m <= 1)
		{
			cout << "Boring!\n";
			continue;
		}

		vector<int> ans = {n};		

		while (n != 1 && n % m == 0)
		{
			n /= m;
			ans.push_back(n);
		}

		if (n != 1) cout << "Boring!";
		else for(int i = 0; i < ans.size(); ++i)
		{
			if (i) cout << ' ';
			cout << ans[i];
		}
		cout << "\n";
	}
}