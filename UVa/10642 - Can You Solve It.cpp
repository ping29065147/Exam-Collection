#include <iostream>

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
	int t, x1, y1, x2, y2;
	int Case = 0;
	cin >> t;

	while (t--)
	{
		int cnt = 0;
		cin >> x1 >> y1 >> x2 >> y2;
			
		while (x1) --x1, ++y1, --cnt;
		while (x2) --x2, ++y2, ++cnt;
		for (int i = y1 + 1; i <= y2; ++i) cnt += i;

		cout << "Case " << ++Case << ": " << cnt << "\n";
	}
}