#include <iostream>
#include <climits>
#include <cstring>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int map[100][100] = {};
bool visit[100][100] = {};
int N;

void dfs(int x, int y, int rain) {
    for(int i = 0; i < 4; i++) {
        if ((x + dx[i] < 0 || x + dx[i] >= N) || (y + dy[i] < 0 || y + dy[i] >= N)) {
            continue;
        }

        if (map[x + dx[i]][y + dy[i]] > rain && visit[x + dx[i]][y + dy[i]] == false) {
            visit[x + dx[i]][y + dy[i]] = true;
            dfs(x + dx[i], y + dy[i], rain);
        }
    }
}

int main() {
    int max = INT_MIN, count = 0;
    int maxHeight = INT_MIN;
    

    cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> map[i][j];
            if (map[i][j] > maxHeight) {
                maxHeight = map[i][j];
            }
        }
    }

    for(int rain = 0; rain < maxHeight; rain++) {
        memset(visit, false, sizeof(visit));
        count = 0;
        
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if (map[i][j] > rain && visit[i][j] == false) {
                    dfs(i, j, rain);
                    count++;
                }
            }
        }
        if (count > max) {
            max = count;
        }
    }

    cout << max;
}