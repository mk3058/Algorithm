#include <iostream>

using namespace std;

int M, N, J;

int main() {
    int prev = 1, cur;
    int count = 0;

    cin >> M >> N >> J;
    for (int i = 1; i <= J; i++) {
        cin >> cur;

        if (cur < prev) {
            count += (prev - cur);
            prev = cur;
        } else if (prev <= cur && cur <= prev + N - 1) {
            // do nothing
        } else {
            count += (cur - (prev + N - 1));
            prev = cur - N + 1;
        }
    }
    cout << count;
}