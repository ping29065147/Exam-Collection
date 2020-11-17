#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int P, C, count = 1;

	while (cin >> P >> C && P != 0 && C != 0) {
		
		deque<int> line;
		char state;
		int s;

		for (int i = 1; i <= min(P, C); i++) line.emplace_back(i);

		cout << "Case " << count++ << ":\n";
		while (C-- && cin >> state) {

			if (state == 'N') {
				cout << line.front() << "\n";
				line.emplace_back(line.front());
				line.pop_front();
			}
			else {
				cin >> s;
				for (auto it = line.begin(); it != line.end(); it++)
					if (*it == s) {
						line.erase(it);
						break;
					}
				line.emplace_front(s);
			}
		}
	}

	return 0;
}