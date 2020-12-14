#include <iostream>
#include <memory.h>
#include <queue>
#include <tuple>

using namespace std;
typedef tuple<int, int, int> tp;

int N, M;
int map[1001][1001];
int vals[1001][1001];
bool vis[1001][1001];
int d[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
priority_queue< tp, vector<tp>, greater<tp> > pq;

void dijkstra()
{
	vals[0][0] = map[0][0];
	pq.push(make_tuple(map[0][0], 0, 0));

	while (!pq.empty())
	{
		auto [val, x, y] = pq.top();
		pq.pop();
		vis[x][y] = true;

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + d[i][0];
			int ny = y + d[i][1];

			if (nx >= 0 && nx < N && ny >= 0 && ny < M && !vis[nx][ny])
			{
				int tmp = val + map[nx][ny];
				if (vals[nx][ny] == -1 || vals[nx][ny] > tmp)
				{
					vals[nx][ny] = tmp;
					pq.push(make_tuple(tmp, nx, ny));
				}
			}
		}
	}

	cout << vals[N - 1][M - 1] << "\n";
}

int main()
{
	// fast io
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;

	while (T--)
	{
		cin >> N >> M;

		// init
		memset(map, 0, sizeof(map));
		memset(vis, false, sizeof(vis));
		memset(vals, -1, sizeof(vals));

		// store data in map
		for (int i = 0, val; i < N; ++i) for (int j = 0; j < M; ++j)
		{
			cin >> val;
			map[i][j] = val;
		}

		// dijkstra algorithm
		dijkstra();
	}

	return 0;
}