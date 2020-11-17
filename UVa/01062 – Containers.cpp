#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string in;
	int count = 1;

	while (cin >> in && in != "end") {

		vector<char> re;
		re.emplace_back(in[0]);

		for (size_t i = 1; i < in.size(); ++i) {
			if (in[i] > re.back()) re.emplace_back(in[i]);
			else *lower_bound(re.begin(), re.end(), in[i]) = in[i];
		}

		cout << "Case " << count++ << ": " << re.size() << "\n";
	}

	return 0;
}
