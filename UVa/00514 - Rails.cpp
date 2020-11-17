#include <iostream>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, in;

	while (cin >> n && n) {
		while (cin >> in && in) {
			
			bool success = true;
			stack<int> A, station;
			for (int i = n; i > 0; --i) A.emplace(i);

			for (int i = 0; i < n; ++i) {

				if (i) cin >> in;
				if (!station.empty() && station.top() == in) station.pop();
				else {
					while (!A.empty() && A.top() != in) station.emplace(A.top()), A.pop();
					if (A.empty()) success = false;
					else A.pop();
				}
			}

			cout << (success ? "Yes\n" : "No\n");
		}
		cout << "\n";
	}

	return 0;
}