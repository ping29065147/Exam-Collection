#include <iostream>
#include <memory.h>

using namespace std;

int N;
int G[152][76];
int sum[76];

// Kadane's Algorithm
int max1d()
{
	int globalmax, localmax, globalmin, localmin, total;
	globalmax = localmax = globalmin = localmin = total = sum[0];

	for (int i = 1; i < N; ++i)
	{
		total += sum[i];

		localmax = max(localmax + sum[i], sum[i]);
		localmin = min(localmin + sum[i], sum[i]);

		globalmax = max(globalmax, localmax);
		globalmin = min(globalmin, localmin);
	}

	return max(globalmax, total - globalmin);
}

int main()
{
	// fast io
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T-- && cin >> N)
	{
		memset(G, 0, sizeof(G));
		int Max = -100;

		// store data in graph
		for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) cin >> G[i][j];
		
		for (int i = 0; i < N; ++i)
		{
			memset(sum, 0, sizeof(sum));

			for (int j = 0, st = i; j < N; ++j, ++st)
			{
				if (st == N) st = 0;
				for (int k = 0; k < N; ++k) sum[k] += G[k][st];
				Max = max(Max, max1d());
			}
		}

		cout << Max << "\n";
	}

	return 0;
}