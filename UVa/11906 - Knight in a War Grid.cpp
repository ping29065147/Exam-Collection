#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> > square;
vector< pair<int, int> > n;
int R, C, M, N, W;

void dfs(int x, int y)
{
	if (square[x][y]++ != 0) return;

	for (int i = 0, nx, ny; i < 8; ++i) {
		nx = x + n[i].first;
		ny = y + n[i].second;
		if (nx >= 0 && ny >= 0 && nx < R && ny < C && square[nx][ny] != -1) dfs(nx, ny);		
		if (i == 3 && (!n[i].first || !n[i].second)) break;
		if (i == 1 && n[i].first == n[i].second) i += 4;
	}
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T, Case = 0;
	cin >> T;

	while (T--) {
		
		cin >> R >> C >> M >> N >> W;

		square.clear();
		square.assign(R, vector<int>(C));
		n.clear();
		n.emplace_back(make_pair(M, N));
		n.emplace_back(make_pair(-M, -N));
		n.emplace_back(make_pair(N, M));
		n.emplace_back(make_pair(-N, -M));
		n.emplace_back(make_pair(-N, M));
		n.emplace_back(make_pair(N, -M));
		n.emplace_back(make_pair(-M, N));
		n.emplace_back(make_pair(M, -N));		
			
		while (W--) {
			int a, b;
			cin >> a >> b;
			square[a][b] = -1;
		}

		dfs(0, 0);
		++square[0][0];

		int odd = 0, even = 0;
		for (auto& i : square) 
			for (auto& j : i) if (j > 0) j & 1 ? ++odd : ++even;

		cout << "Case " << ++Case << ": " << even << " " << odd << "\n";
	}

	return 0;
}