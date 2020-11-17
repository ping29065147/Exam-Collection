#include <iostream>
#include <set>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, k, temp;
	unsigned long long total;
	multiset<int> bill;

	while (cin >> n && n) {
		total = 0;
		bill.clear();

		while (n--) {
			cin >> k;
			for (size_t i = 0; i < k; i++) cin >> temp, bill.emplace(temp);
			total += *bill.rbegin() - *bill.begin();
			bill.erase(bill.begin());
			auto it = bill.end();
			bill.erase(--it);
		}
		cout << total << "\n";
	}

	return 0;
}