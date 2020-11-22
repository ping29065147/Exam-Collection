#include <iostream>
#include <vector>
#include <unordered_set>
#include <stack>

using namespace std;

vector<int> graph[26];
stack<char> result;
bool check[26]{}, path[26]{};

void dfs(int num)
{
	check[num] = true;
	for (auto& i : graph[num])
		if (!check[i]) dfs(i);
	result.emplace(num + 'A');
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string str1, str2;
	cin >> str1;

	unordered_set<int> us;

	while (cin >> str2 && str2 != "#") {		

		for (int i = 0; str1[i] && str2[i]; ++i) {

			us.emplace(str1[i] - 'A');
			us.emplace(str2[i] - 'A');

			if (str1[i] != str2[i]) {
				graph[str1[i] - 'A'].emplace_back(str2[i] - 'A');
				path[str2[i] - 'A'] = true;
				break;
			}
		}

		str1 = str2;
	}

	for (auto& i : us)
		if (!path[i]) dfs(i);

	while (!result.empty()) cout << result.top(), result.pop();
	cout << "\n";

	return 0;
}