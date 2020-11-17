#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, b, sg, sb, temp;
	multiset<int> green, blue;
	vector<int> battle;

	cin >> n;
	while (n--) {
		cin >> b >> sg >> sb;

		while (sg--) cin >> temp, green.emplace(temp);
		while (sb--) cin >> temp, blue.emplace(temp);

		while (!green.empty() && !blue.empty()) {
			for (size_t i = 0; i < b; i++) {
				if (green.empty() || blue.empty()) break;
				battle.emplace_back(*green.rbegin() - *blue.rbegin());
				auto it = green.end();
				green.erase(--it);
				it = blue.end();
				blue.erase(--it);
			}

			for (auto& tmp : battle) {
				if (tmp > 0) green.emplace(tmp);
				else if (tmp < 0) blue.emplace(-tmp);
			}
			battle.clear();
		}

		if (green.empty() && blue.empty()) cout << "green and blue died\n";
		else if (green.empty()) {
			cout << "blue wins\n";
			for (auto it = blue.rbegin(); it != blue.rend(); it++) cout << *it << "\n";
			blue.clear();
		}
		else {
			cout << "green wins\n";
			for (auto it = green.rbegin(); it != green.rend(); it++) cout << *it << "\n";
			green.clear();
		}
		if (n) cout << "\n";
	}

	return 0;
}
