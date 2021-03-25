#include <iostream>

using namespace std;

int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M, D;	
	cin >> N;

	while (N--)
	{
		cin >> M >> D;

		int day = D;
		for (int i = 1; i < M; ++i) day += days[i];

		day %= 7;	
		if (day == 0) cout << "Friday\n";
		else if (day == 1) cout << "Saturday\n";
		else if (day == 2) cout << "Sunday\n";
		else if (day == 3) cout << "Monday\n";
		else if (day == 4) cout << "Tuesday\n";
		else if (day == 5) cout << "Wednesday\n";
		else if (day == 6) cout << "Thursday\n";		
	}

	return 0;
}