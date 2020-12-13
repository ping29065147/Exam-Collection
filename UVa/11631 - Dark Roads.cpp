#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

vector< tuple<int, int, int> > edge;
vector<int> parents;
vector<int> ranks;
int cost;

bool cmp(tuple<int, int, int> r1, tuple<int, int, int> r2)
{
	return get<2>(r1) < get<2>(r2);
}

bool union_find(int r1, int r2)
{
	// find root of r1 and r2
	while (r1 != parents[r1]) r1 = parents[r1];
	while (r2 != parents[r2]) r2 = parents[r2];

	// circle
	if (r1 == r2) return false;

	if (ranks[r1] > ranks[r2]) parents[r2] = r1;
	else if (ranks[r2] > ranks[r1]) parents[r1] = r2;
	else parents[r2] = r1, ++ranks[r1];

	return true;
}

int kruskcal(int m)
{
	sort(edge.begin(), edge.end(), cmp);

	int side = 0;
	for (auto& [r1, r2, w] : edge)
	{
		if (side == m - 1) break;

		// union find algorithm
		if (union_find(r1, r2))
		{
			cost -= w;
			++side;
		}
	}

	return cost;
}

int main()
{
	// fast io
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int m, n;
	while (cin >> m >> n, m && n)
	{
		// init
		edge.clear();
		parents.clear();
		ranks.assign(m, 0);
		for (int i = 0; i < m; ++i) parents.emplace_back(i);
		cost = 0;

		// store roads in edges
		while (n--)
		{
			int x, y, z;
			cin >> x >> y >> z;
			cost += z;
			edge.push_back({ x, y, z });
		}

		// kruskcal algorithm
		cout << kruskcal(m) << "\n";
	}

	return 0;
}