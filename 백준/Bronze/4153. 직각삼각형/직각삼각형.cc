#include <iostream>

using namespace std;

int main() {
  int length[3];
  int max;

  while (true) {

    int max = -1;
    int idx = -1;
    for (int i = 0; i < 3; i++) {
      cin >> length[i];
      if (length[i] > max) {
        max = length[i];
        idx = i;
      }
    }
    if (!length[0] && !length[1] && !length[2]) {
      break;
    }

    int max_sq = max * max;
    for (int i = 0; i < 3; i++) {
      if (i != idx) {
        max_sq = max_sq - (length[i] * length[i]);
      }
    }
    
    if (!max_sq) {
      cout << "right\n";
    } else {
      cout << "wrong\n";
    }
  }
}