#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int c;
	cin >> c;

	while (c--) {

		int n, t, m, in;
		string side;
		pair<int, int> temp;
		queue< pair<int, int> > boatl, boatr;

		cin >> n >> t >> m;	
		for (size_t i = 0; i < m; ++i) {		
			cin >> temp.first >> side;
			temp.second = i;
			side == "left" ? boatl.emplace(temp) : boatr.emplace(temp);
		}

		int time = 0;
		auto cur = &boatl;
		vector<int> result(m);
		while (!boatl.empty() || !boatr.empty()) {

			if (boatr.empty()) {			
				time = max(time, boatl.front().first);
				if (*cur == boatr) time += t, cur = &boatl;
			}
			else if (boatl.empty()) {
				time = max(time, boatr.front().first);
				if (*cur == boatl) time += t, cur = &boatr;
			}
			else {
				auto small = (boatl.front().first < boatr.front().first) ? &boatl : &boatr;
				if (boatl.front().first == boatr.front().first) small = cur;

				if (time >= small->front().first) {
					if (small != cur && time < cur->front().first)
						time += t, cur = small;
				}
				else {
					time = small->front().first;
					if (small != cur) time += t, cur = small;				
				}
			}

			for (size_t i = 0; i < n && !cur->empty(); ++i)
				if (cur->front().first <= time) result[cur->front().second] = time + t, cur->pop();
			time += t;
			if (*cur == boatl) cur = &boatr;
			else cur = &boatl;
		}

		for (auto& i : result) cout << i << "\n";
		if(c) cout << "\n";
	}

	return 0;
}