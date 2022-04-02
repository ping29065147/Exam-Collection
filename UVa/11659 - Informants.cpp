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
	int n, a, x, y;

	while (cin >> n >> a, n + a)
	{
		// init
		vector<int> correct(n + 1, 0);
		vector<int> wrong(n + 1, 0);
		int max_num = (1 << n);
		int ret = 0;

		// input
		for (int i = 0; i < a; ++i)
		{
			cin >> x >> y;
			if (y > 0) correct[x] |= (1 << (y - 1));  // if 1 trust 3 and 4, correct[1] = 1100
			else wrong[x] |= (1 << (-y - 1));
		}

		for (int i = 0; i < max_num; ++i) // all possible combination
		{
			bool feasible = true;

			for (int j = 1; j <= n; ++j) // each person 
			{
				int p = 1 << (j - 1);
				if ((i & p) == 0) continue; // j doesn't exist in i
				if ((i & wrong[j]) != 0 || (i & correct[j]) != correct[j]) // is there a contradiction
				{
					feasible = false;
					break;
				}
			}

			if (feasible)
			{
				int cnt = 0, cpy = i;
				while (cpy) cnt += cpy & 1, cpy >>= 1; // count the number of '1' in i (bitwise)
				ret = max(ret, cnt);
			}
		}

		cout << ret << "\n";
	}
}