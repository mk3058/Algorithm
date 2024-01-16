#include <climits>
#include <iostream>

using namespace std;

/**
 * 경우의 수
 *  가격이 최고점에 도달하지 않은 경우 -> 주식을 한개 산다
 *  가격이 최고점에 도달한 경우 -> 주식을 모두 판다
 *  -> 최적부분구조
 *
 *  오늘의 선택이 내일 선택을 제약하는가? -> X -> greedy choice property
 *
 *  -> 그리디?
 */

int price[1000001];
int totalDays = 0;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int test_case;
  cin >> test_case;

  for (int t = 0; t < test_case; t++) {
    long long profit = 0;

    cin >> totalDays;
    for (int i = 1; i <= totalDays; i++) {
      cin >> price[i];
    }
    // 입력

    int i = 1;
    while (i <= totalDays) {
      int max = INT_MIN;
      int idx = 0, accumulatedPrice = 0, tmp = 0;

      for (int k = i; k <= totalDays; k++) {
        if (price[k] > max) {
          max = price[k];
          idx = k;
          accumulatedPrice = tmp;
          if (max == 10000) {
            break;
          }
        }
        tmp += price[k];
      }
      // 최댓값 index와 그때의 비용 계산

      if (i <= idx - 1) {
        profit += (((idx - i) * price[idx]) - accumulatedPrice);
      }
      // 손익 계산. (판매 - 구매) 누적
      i = idx + 1;
    }

    if (profit < 0) {
      profit = 0;
    }

    cout << profit << '\n';
  }
}