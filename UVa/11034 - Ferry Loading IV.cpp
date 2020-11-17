#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int c, l, m, length;
	string side;
	cin >> c;

	while (c--) {

		int time = 0;
		queue<int> L, R;
		auto cur = &L;

		cin >> l >> m;
		l *= 100;
		while (m--) {
			cin >> length >> side;
			side == "left" ? L.emplace(length) : R.emplace(length);
		}

		while (!L.empty() || !R.empty()) {
			int sum = 0;
			while (!cur->empty() && sum + cur->front() <= l) sum += cur->front(), cur->pop();
			++time;
			cur = *cur == L ? &R : &L;
		}

		cout << time << "\n";
	}

	return 0;
}