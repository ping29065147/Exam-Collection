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
	int n, num;

	while (cin >> n)
	{
		vector<long long> buf = {1};

		while (n--)
		{
			cin >> num;
			vector<long long> t = { -num, 1 };
			vector<long long> mul(buf.size() + t.size(), 0);

			for (int i = 0; i < buf.size(); ++i)
				for (int j = 0; j < t.size(); ++j)
					mul[i + j] += buf[i] * t[j];

			while (!mul.empty() && mul.back() == 0) mul.pop_back();
			buf = mul;
		}
		
		for (int i = buf.size() - 1; i >= 0; --i)
		{
			if (buf[i] == 0 && i != 0) continue;
			if (i != buf.size() - 1) cout << (buf[i] >= 0 ? " + " : " - ");
			if ((buf[i] != 1 && buf[i] != -1) || i == 0) cout << (buf[i] > 0 ? buf[i] : -buf[i]);
			if (i != 0) cout << "x";
			if (i > 1) cout << "^" << i;		
		}
		cout << " = 0\n";
	}
}