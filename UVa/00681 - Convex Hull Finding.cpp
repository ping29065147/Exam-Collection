#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

struct point
{
	int x;
	int y;
};

int T, N;
vector< point > V;
vector< point > ret;

static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

void init()
{
	V.clear();
	ret.clear();
}

void read(int t)
{
	int a, b, _;

	cin >> N;
	for (int i = 0; i < N; ++i) cin >> a >> b, V.push_back({ a, b });
	if (t != T) cin >> _;
}

double cross(point& o, point& a, point& b)
{
	return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

void Andrews_Monotone_Chain()
{
	sort(V.begin(), V.end(), [](point& a, point& b)
		{ return a.y < b.y || (a.y == b.y && a.x < b.x); });

	for (int i = 0; i < N; ++i)
	{
		int m = ret.size();
		while (m >= 2 && cross(ret[m - 2], ret[m - 1], V[i]) <= 0)
		{
			ret.pop_back();
			--m;
		}
		ret.emplace_back(V[i]);
	}

	for (int i = N - 2, t = ret.size() + 1; i >= 0; --i)
	{
		int m = ret.size();
		while (m >= t && cross(ret[m - 2], ret[m - 1], V[i]) <= 0)
		{
			ret.pop_back();
			--m;
		}
		ret.emplace_back(V[i]);
	}
}

void print(int t)
{
	cout << ret.size() << "\n";
	for (auto& [x, y] : ret) cout << x << " " << y << "\n";
	if (t != T) cout << "-1\n";
}

int main()
{
	cin >> T;
	cout << T << "\n";

	for (int i = 1; i <= T; ++i)
	{
		init();
		read(i);
		Andrews_Monotone_Chain();
		print(i);
	}
}