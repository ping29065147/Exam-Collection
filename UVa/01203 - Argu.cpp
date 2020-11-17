#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
typedef tuple<int, int, int> datas;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	priority_queue<datas, vector<datas>, greater<datas>> lists;
	string input;
	int Q, P, num, ps;

	while (cin >> input && input != "#" && cin >> Q >> P) lists.emplace(make_tuple(P, Q, P));
	
	cin >> num;
	while (num--) {
		tie(ps, Q, P) = lists.top();
		lists.pop();
		lists.emplace(make_tuple(ps + P, Q, P));
		cout << Q << "\n";
	}

	return 0;
}
