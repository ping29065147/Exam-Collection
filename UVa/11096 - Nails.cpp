#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>

using namespace std;

struct point
{
	double x;
	double y;
};

int T, N;
double L;
vector<point> V;
vector<point> ret;

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

void read()
{
	int a, b;
	cin >> L >> N;
	for (int i = 0; i < N; ++i) cin >> a >> b, V.push_back({ a, b });
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

double dis(point& a, point& b)
{
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

void print()
{
	double ans = 0;
	for (int i = 0; i < ret.size() - 1; ++i) ans += dis(ret[i], ret[i + 1]);

	cout << setprecision(5) << fixed << max(ans, L) << "\n";
}

int main()
{
	cin >> T;
	while (T--)
	{
		init();
		read();
		Andrews_Monotone_Chain();
		print();
	}
}