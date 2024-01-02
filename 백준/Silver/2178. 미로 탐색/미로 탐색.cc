#include <queue>
#include <iostream>

using namespace std;

enum {WALL, PATH, VISITED};

int main() {
    int count = 0;
    int map[100][100] = {};
    queue<pair<int, int> > nodes;
    int m, n;
    int x = 0, y = 0;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    cin >> m >> n;
    cin.clear();

    string input;
    for(int i = 0; i < m; i++) {
        cin >> input;
        for(int j = 0; j < n; j++) {
            map[i][j] = input.at(j) - '0';
        }
        cin.clear();
    }

    nodes.push(pair<int, int>(0, 0));
    map[0][0] = VISITED;
    while(!nodes.empty()) {
        int size = nodes.size();
        count++;

        for(int j = 0; j < size; j++) {
            x = nodes.front().first;
            y = nodes.front().second;
            nodes.pop();

            if (x == m - 1 && y == n - 1) {
                cout << count << endl;
                return 0;
            }

            for(int i = 0; i < 4; i++) {
                if(!((0 <= x + dx[i] && x + dx[i] < m) && (0 <= y + dy[i] && y + dy[i] < n))) {
                    continue;
                }
                if (map[x + dx[i]][y + dy[i]] == PATH) {
                    map[x + dx[i]][y + dy[i]] = VISITED;
                    nodes.push(pair<int, int>(x + dx[i], y + dy[i]));
                }
            }
        }
    }
}