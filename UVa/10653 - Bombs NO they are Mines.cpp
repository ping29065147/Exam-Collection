#include <iostream>
#include <vector>
#include <memory.h>
#include <queue>

using namespace std;

const int nxt[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
int M[1002][1002];
int R, C;
int x_1, y_1, x_2, y_2;

int bfs()
{
    queue< pair<int, int> > Q;
    Q.push({ x_1, y_1 });
    M[x_1][y_1] = 1;

    while (!Q.empty())
    {
        auto [ux, uy] = Q.front();
        Q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int vx = ux + nxt[i][0];
            int vy = uy + nxt[i][1];

            if (vx >= 0 && vy >= 0 && vx < R && vy < C && !M[vx][vy])
            {
                M[vx][vy] = M[ux][uy] + 1;
                if (vx == x_2 && vy == y_2) return M[vx][vy] - 1;
                Q.push({ vx, vy });
            }
        }
    }

    return -1;
}

int main()
{
    // fast io
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, r, k, c;
    while (cin >> R >> C, R && C)
    {
        memset(M, 0, sizeof(M));

        // build map
        cin >> N;
        while (N--)
        {
            cin >> r >> k;
            while (k--)
            {
                cin >> c;
                M[r][c] = 1;
            }
        }

        cin >> x_1 >> y_1 >> x_2 >> y_2;		
        cout << bfs() << "\n";
    }

    return 0;
}