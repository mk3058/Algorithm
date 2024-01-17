#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, C;
vector<pair<int, int> > cnt;

bool compare(pair<int, int> a, pair<int, int> b) { return a.second > b.second; }

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> C;
  cnt.reserve(1001);

  int input;
  for (int i = 0; i < N; i++) {
    bool flag = true;
    cin >> input;

    for (auto &it : cnt) {
      if (it.first == input) {
        flag = false;
        it.second = it.second + 1;
      }
    }
    if (flag) {
      cnt.insert(cnt.end(), make_pair(input, 1));
    }
  }

  stable_sort(cnt.begin(), cnt.end(), compare);
  for (auto it : cnt) {
    for (int i = 0; i < it.second; i++) {
      cout << it.first << " ";
    }
  }
}