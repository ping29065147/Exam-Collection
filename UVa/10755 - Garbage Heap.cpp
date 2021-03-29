#include <iostream>
#include <memory.h>
#include <climits>

using namespace std;

int T, A, B, C;
long long G[21][21][21];
long long sum2d[21][21];
long long sum1d[21];

// Kadane's Algorithm
long long get_max1d()
{
	long long Max1d, localmax;
	Max1d = localmax = sum1d[0];

	for (int i = 1; i < A; ++i)
	{
		localmax = max(localmax + sum1d[i], sum1d[i]);
		Max1d = max(Max1d, localmax);
	}

	return Max1d;
}

long long get_max2d()
{
	long long Max2d = LLONG_MIN;

	for (int i = 0; i < B; ++i)
	{
		memset(sum1d, 0, sizeof(sum1d));

		for (int j = i; j < B; ++j)
		{
			for (int k = 0; k < A; ++k) sum1d[k] += sum2d[k][j];
			Max2d = max(Max2d, get_max1d());
		}
	}

	return Max2d;
}

long long get_max3d()
{
	long long Max3d = LLONG_MIN;

	for (int i = 0; i < C; ++i)
	{
		memset(sum2d, 0, sizeof(sum2d));

		for (int j = i; j < C; ++j)
		{
			for (int k = 0; k < A; ++k) for (int l = 0; l < B; ++l) sum2d[k][l] += G[k][l][j];
			Max3d = max(Max3d, get_max2d());
		}
	}

	return Max3d;
}

int main()
{
	// fast io
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	cin >> T;

	while (T-- && cin >> A >> B >> C)
	{
		// store data in graph
		for (int i = 0; i < A; ++i) for (int j = 0; j < B; ++j) for (int k = 0; k < C; ++k)
			cin >> G[i][j][k];

		cout << get_max3d() << (T ? "\n\n" : "\n");
	}

	return 0;
}