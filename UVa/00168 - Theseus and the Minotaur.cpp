#include <iostream>
#include <vector>

using namespace std;

vector< vector<char> > graph;
vector<bool> light;
int step, k;

void dfs(char m, char t)
{
	if (step && step % k == 0) cout << t << " ", light[t- 'A'] = true;

	for (size_t i = 0; i < graph[m - 'A'].size(); ++i)
		if (graph[m - 'A'][i] != t && !light[graph[m - 'A'][i] - 'A']) {
			++step, dfs(graph[m - 'A'][i], m);
			return;
		}

	cout << "/" << m << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string in;
	char m, t;

	while (cin >> in && in != "#") {	
		
		graph.assign(26, vector<char>());
		light.assign(26, false);
		step = 0;
		
		cin >> m >> t >> k;

		for (size_t i = 0; i < in.size();)
			if (in[i++] == ':') {
				auto p = i - 2;
				while (in[i] != ';' && in[i] != '.') graph[in[p] - 'A'].emplace_back(in[i++]);
			}
				
		dfs(m, t);
	}

	return 0;
}