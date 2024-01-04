#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int M, N, K;
int map[100][100] = {};

int dfs(int x, int y) {
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int size = 0;

    if (map[x][y] == 1) {
        return 0;
    }

    map[x][y] = 1;
    size = 1;
    for (int i = 0; i < 4; i++) {
        if ((x + dx[i] < 0 || x + dx[i] >= N) ||
            (y + dy[i] < 0 || y + dy[i] >= M)) {
            continue;
        }

        size += dfs(x + dx[i], y + dy[i]);
    }
    return size;
}

int main() {
    int lx, ly, rx, ry;
    int count = 0;
    vector<int> area;

    cin >> M >> N >> K;

    for (int i = 0; i < K; i++) {
        cin >> lx >> ly >> rx >> ry;

        for (int j = lx; j < rx; j++) {
            for (int k = M - ry; k < M - ly; k++) {
                map[j][k] = 1;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 0) {
                count++;
                area.push_back(dfs(i, j));
            }
        }
    }

    sort(area.begin(), area.end());
    cout << count << endl;
    for (int i : area) {
        cout << i << " ";
    }
}