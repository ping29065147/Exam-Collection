#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int T, N, put, high, low;
    int a, b;
    vector<int> walls;
    cin >> T;

    for(a=1; a<=T; a++){
        high=0;
        low=0;
        walls.assign(N, 0);

        cin >> N;
        for(b=0; b<N; b++){
            cin >> put;
            walls[b] = put;
        }

        for(b=0; b<N-1; b++){
            if (walls[b+1] > walls[b])
                high++;
            else if (walls[b+1] < walls[b])
                low++;
        }

        cout << "Case " << a << ": " << high << " " << low << endl;
    }

    return 0;
}
