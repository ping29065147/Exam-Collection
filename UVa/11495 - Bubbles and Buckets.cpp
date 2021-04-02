#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int ans;

// merge sort
void merge(vector<int>& P, int front, int mid, int end)
{
	vector<int> left(P.begin() + front, P.begin() + mid + 1);
	vector<int> right(P.begin() + mid + 1, P.begin() + end + 1);
	
	left.emplace_back(INT_MAX);
	right.emplace_back(INT_MAX);

	int l = 0, r = 0;
	for (int i = front; i <= end; ++i)
	{
		if (left[l] <= right[r]) P[i] = left[l++];
		else
		{
			P[i] = right[r++];
			ans += left.size() - l - 1;
		}
	}
}

// merge function
void mergesort(vector<int>& P, int front, int end)
{
	if (front < end)
	{
		int mid = (front + end) / 2;
		mergesort(P, front, mid);
		mergesort(P, mid + 1, end);
		merge(P, front, mid, end);
	}
}

int main()
{
	// fast io
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	int N;
	vector<int> P;

	while (cin >> N, N)
	{
		P.assign(N + 1, 0);
		for (int i = 0; i < N; ++i) cin >> P[i];

		ans = 0;
		mergesort(P, 0, N - 1);

		cout << (ans % 2 ? "Marcelo\n" : "Carlos\n");
	}

	return 0;
}