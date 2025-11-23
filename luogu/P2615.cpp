#include <iostream>
using namespace std;
int main()
{
    int N, M[40][40] = {0}, Pos[39 * 39 + 1][2];
    cin >> N;
    M[1][N / 2 + 1] = 1;
    Pos[1][0] = 1;
    Pos[1][1] = N / 2 + 1;
    for (int K = 2; K < N * N + 1; ++K)
    {
        if (Pos[K-1][0] == 1 && Pos[K-1][1] != N)
        {
            Pos[K][0] = N;
            Pos[K][1] = Pos[K - 1][1] + 1;
            M[Pos[K][0]][Pos[K][1]] = K;
        }else if (Pos[K-1][1] == N && Pos[K-1][0] != 1)
        {
            Pos[K][0] = Pos[K - 1][0] - 1;
            Pos[K][1] = 1;
            M[Pos[K][0]][Pos[K][1]] = K;
        }else if (Pos[K-1][0] == 1 && Pos[K-1][1] == N)
        {
            Pos[K][0] = Pos[K - 1][0] + 1;
            Pos[K][1] = Pos[K - 1][1];
            M[Pos[K][0]][Pos[K][1]] = K;
        }
        else if (Pos[K - 1][0] != 1 && Pos[K - 1][1] != N)
        {
            if (M[Pos[K-1][0] - 1][Pos[K-1][1] + 1] == 0)
            {
                Pos[K][0] = Pos[K - 1][0] - 1;
                Pos[K][1] = Pos[K - 1][1] + 1;
                M[Pos[K][0]][Pos[K][1]] = K;
            }else
            {
                Pos[K][0] = Pos[K - 1][0] + 1;
                Pos[K][1] = Pos[K - 1][1];
                M[Pos[K][0]][Pos[K][1]] = K;
            }
        }
    }

    for (int i = 1; i < N + 1; ++i)
    {
        for (int j = 1; j < N + 1; ++j)
            cout << M[i][j] << " ";
        cout << endl;
    }
}