#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

pair<int, int> Move[] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
int T, N, M;
int x_cnt, b_cnt;
int _s = 0, _t;
vector< vector<char> > G;
vector< vector<int> > B;
vector< vector<int> > X;
vector< vector<int> > dis;
vector< vector<int> > edge;
vector< vector<int> > cost;
vector< vector<int> > capacity;
vector< vector<int> > net;
vector<int> d;
vector<int> p;

void init()
{
	x_cnt = b_cnt = 0;
	G.assign(200, vector<char>(200));
	B.assign(200, vector<int>(200, INT_MAX));
	X.assign(200, vector<int>(200, 0));
	edge.assign(200, vector<int>());
	cost.assign(200, vector<int>(200, 0));
	capacity.assign(200, vector<int>(200, 0));
	net.assign(200, vector<int>(200, 0));
	p.assign(200, 0);
}

void bfs(int i, int j, int cur)
{
	dis.assign(200, vector<int>(200, INT_MAX / 2));
	dis[i][j] = 0;

	queue< pair<int, int> > Q;
	Q.push({ j, i });

	while (!Q.empty())
	{
		auto [x, y] = Q.front();
		Q.pop();

		if (G[y][x] == 'X') B[cur][X[y][x]] = dis[y][x];

		for (int i = 0; i < 4; ++i)
		{
			int newx = x + Move[i].first;
			int newy = y + Move[i].second;			

			if (newx >= 0 && newx < M && newy >= 0 && newy < N && G[newy][newx] != '#' && dis[newy][newx] > dis[y][x] + 1)
			{			
				dis[newy][newx] = dis[y][x] + 1;
				Q.push({ newx, newy });
			}
		}
	}
}

void read()
{
	cin >> N >> M;
	for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j)
	{
		cin >> G[i][j];
		if (G[i][j] == 'X') X[i][j] = x_cnt++;
	}

	for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j)
		if (G[i][j] == 'B') bfs(i, j, b_cnt++);

	_t = x_cnt + b_cnt + 1;
	for (int i = 0; i < b_cnt; ++i)
	{
		edge[_s].emplace_back(i + 1);
		edge[i + 1].emplace_back(_s);
		capacity[_s][i + 1] = 1;
		capacity[i + 1][_s] = 0;
		cost[_s][i + 1] = 0;
		cost[i + 1][_s] = 0;

		for (int j = 0; j < x_cnt; ++j) if (B[i][j] != INT_MAX)
		{
			edge[i + 1].emplace_back(j + b_cnt + 1);
			edge[j + b_cnt + 1].emplace_back(i + 1);
			cost[i + 1][j + b_cnt + 1] = B[i][j];
			cost[j + b_cnt + 1][i + 1] = 0;
			capacity[i + 1][j + b_cnt + 1] = 1;
			capacity[j + b_cnt + 1][i + 1] = 0;
		}
	}

	for (int j = b_cnt + 1; j <= b_cnt + x_cnt; ++j)
	{
		edge[j].emplace_back(_t);
		edge[_t].emplace_back(j);
		cost[j][_t] = 0;
		cost[_t][j] = 0;
		capacity[j][_t] = 1;
		capacity[_t][j] = 0;
	}
}

bool bellman()
{
	d.assign(200, INT_MAX);
	d[_s] = 0;

	queue<int> Q;
	vector<bool> inQ(200, false);
	Q.emplace(_s);
	inQ[_s] = true;

	while (!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		inQ[u] = false;

		for (auto& v : edge[u])
		{
			if (net[v][u] > 0 && d[u] + (-cost[v][u]) < d[v])
				d[v] = d[u] + (-cost[v][u]);
			else if (capacity[u][v] > net[u][v] && d[u] + cost[u][v] < d[v])
				d[v] = d[u] + cost[u][v];
			else continue;

			p[v] = u;
			if (!inQ[v]) Q.emplace(v), inQ[v] = true;
		}
	}

	if (d[_t] == INT_MAX) return false;
	else return true;
}

void updateflow(int u, int v, int c)
{
	if (v == _s) return;
	net[u][v] += c;
	net[v][u] -= c;
	updateflow(p[u], u, c);
}

int maxflow()
{
	int ret = 0;

	while (bellman())
	{
		ret += d[_t];
		updateflow(p[_t], _t, 1);
	}

	return ret;
}

int main()
{
	cin >> T;

	while (T--)
	{
		init();
		read();
		cout << maxflow() << "\n";
	}
}