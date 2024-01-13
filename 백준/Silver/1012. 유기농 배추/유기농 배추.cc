#include <iostream>

using namespace std;

int T, M, N, K, X, Y;


void mark(int x, int y, bool map[50][50]) {
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1}; 

    if (map[x][y]) {
        map[x][y] = false;
        for(int i = 0; i < 4; i++) {
            if ((x + dx[i] < 0 || x + dx[i] >= M) || (y + dy[i] < 0 || y + dy[i] >= N))
                continue;
            
            mark(x + dx[i], y + dy[i], map);
        }
    }
}

int main() {
    cin >> T;

    for(int test_case = 0; test_case < T; test_case++) {
        int count = 0;
        bool map[50][50] = {};
        cin >> M >> N >> K;

        for(int i = 0; i < K; i++) {
            cin >> X >> Y;
            map[X][Y] = true;
        }

        for(int i = 0; i < M; i++) {
            for(int j = 0; j < N; j++) {
                if (map[i][j]) {
                    count++;
                    mark(i, j, map);
                }
            }
        }

        cout << count << "\n";
    }
}
