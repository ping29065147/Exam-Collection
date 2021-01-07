#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, e, f, c;
	cin >> N;

	while (N--)
	{
		cin >> e >> f >> c;

		int total = 0, now = e + f;

		while (now >= c)
		{
			total += now / c;
			now = now % c + now / c;
		}

		cout << total << "\n";
	}

	return 0;
}