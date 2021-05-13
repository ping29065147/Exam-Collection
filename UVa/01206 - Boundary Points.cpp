#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

struct point
{
	double x;
	double y;
};

string str;
vector<point> V;
vector<point> ret;

void init()
{
	V.clear();
	ret.clear();
}

void read()
{
	char _;
	double a, b;
	stringstream ss(str);
	while (ss >> _ >> a >> _ >> b >> _) V.push_back({ a, b });
}

double cross(point& o, point& a, point& b)
{
	return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

void Andrews_Monotone_Chain()
{
	sort(V.begin(), V.end(), [](point& a, point& b)
		{ return a.y < b.y || (a.y == b.y && a.x < b.x); });

	for (int i = 0; i < V.size(); ++i)
	{
		int m = ret.size();
		while (m >= 2 && cross(ret[m - 2], ret[m - 1], V[i]) <= 0)
		{
			ret.pop_back();
			--m;
		}
		ret.emplace_back(V[i]);
	}

	for (int i = V.size() - 2, t = ret.size() + 1; i >= 0; --i)
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

void print()
{
	int S = ret.size();
	for (auto& [x, y] : ret)
	{
		cout << "(" << x << "," << y << ")";
		if (--S) cout << " ";
	}
	cout << "\n";
}

int main()
{
	while (getline(cin, str))
	{
		init();
		read();
		Andrews_Monotone_Chain();
		print();
	}
}