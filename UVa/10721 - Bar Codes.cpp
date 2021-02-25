#include <iostream>
#include <memory.h>

using namespace std;

long long bc[51][51][51];

int main()
{
	// fast io
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, k, m;

	for (int i = 0; i < 51; ++i) bc[0][0][i] = 1;

	for (int i = 1; i < 51; ++i) for (int j = 1; j < 51; ++j)
		for (int k = 1; k < 51; ++k) for (int x = 1; x <= i && x <= k; ++x)
			bc[i][j][k] += bc[i - x][j - 1][k];

	while (cin >> n >> k >> m) cout << bc[n][k][m] << "\n";

	return 0;
}