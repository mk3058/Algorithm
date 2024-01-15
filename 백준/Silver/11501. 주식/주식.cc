#include <iostream>

using namespace std;

int price[1000001];
int totalDays = 0;

int main() {
  int test_case;

  cin >> test_case;

  for (int t = 0; t < test_case; t++) {
    long long profit = 0;
    int stockAmount = 0;

    cin >> totalDays;
    for (int i = 1; i <= totalDays; i++) {
      cin >> price[i];
    }

    int i = 1;
    while (i <= totalDays) {
      int max = price[i];
      int idx = i;

      for (int k = i + 1; k <= totalDays; k++) {
        if (price[k] == 10000) {
          idx = k;
          break;
        }
        if (price[k] > max) {
          max = price[k];
          idx = k;
        }
      }

      for (int j = i; j <= idx - 1; j++) {
        stockAmount++;
        profit -= price[j];
      }

      if (stockAmount) {
        profit += (stockAmount * price[idx]);
        stockAmount = 0;
      }
      i = idx + 1;
    }
    if (profit < 0) {
      profit = 0;
    }

    cout << profit << '\n';
  }
}