#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, k, temp;
	size_t total;
	unordered_set<int> snowflake;
	vector<int> cpy;

	cin >> n;
	while (n--) {
		total = 0;
		cin >> k;

		while (k--) {
			cin >> temp;
			if (snowflake.count(temp)) total = max(total, snowflake.size());
			while (snowflake.count(temp)) snowflake.erase(*cpy.begin()), cpy.erase(cpy.begin());
			cpy.emplace_back(temp);
			snowflake.emplace(temp);
		}
		total = max(total, snowflake.size());

		cout << total << "\n";
		snowflake.clear();
		cpy.clear();
	}

	return 0;
}
