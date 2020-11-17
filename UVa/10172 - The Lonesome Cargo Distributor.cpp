#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int SET, N, S, Q, Qi, temp;
	cin >> SET;

	while (SET--) {

		stack<int> carrier;
		vector< queue<int> > stations;
		cin >> N >> S >> Q;

		for (size_t i = 0; i < N; ++i) {
			queue<int> station;
			cin >> Qi;
			for (size_t j = 0; j < Qi; ++j) cin >> temp, station.emplace(temp - 1);
			stations.emplace_back(station);
		}

		int cur = 0, time = 0;
		while (1) {

			while (!carrier.empty() && (carrier.top() == cur || stations[cur].size() < Q)) {
				if (carrier.top() != cur) stations[cur].emplace(carrier.top());
				carrier.pop();
				++time;
			}

			while (!stations[cur].empty() && carrier.size() < S) {
				carrier.emplace(stations[cur].front());
				stations[cur].pop();
				++time;
			}

			bool out = true;
			for (size_t i = 0; i < N; ++i)
				if (!stations[i].empty() || !carrier.empty()) {
					cur = ++cur % N;
					time += 2;
					out = false;
					break;
				}
			if (out) break;
		}

		cout << time << "\n";
	}

	return 0;
}