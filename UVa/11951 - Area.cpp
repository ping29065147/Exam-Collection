#include <iostream>
#include <climits>
#include <memory.h>

using namespace std;

int T, N, M, K;
int l, r, maxS, maxP;
int G[101][101];
int sum[101];

// Kadane's Algorithm
void max1d()
{
	int top = 0, localsum = 0;

	for (int i = 0; i < N; ++i)
	{
		localsum += sum[i];
		while (localsum > K) localsum -= sum[top++];

		int localS = (r - l + 1) * (i - top + 1);
		if (localS > maxS) maxS = localS, maxP = localsum;
		else if (localS == maxS) maxP = min(maxP, localsum);
	}
}

int main()
{
	// fast io
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	cin >> T;

	for (int cases = 1; cases <= T; ++cases)
	{
		cin >> N >> M >> K;
		// init
		memset(G, 0, sizeof(G));
		maxS = 0;
		maxP = INT_MAX;

		// store data in graph
		for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) cin >> G[i][j];

		for (l = 0; l < M; ++l)
		{
			memset(sum, 0, sizeof(sum));

			for (r = l; r < M; ++r)
			{
				for (int i = 0; i < N; ++i) sum[i] += G[i][r];
				max1d();
			}
		}

		cout << "Case #" << cases << ": " << maxS << " " << maxP << "\n";
	}

	return 0;
}