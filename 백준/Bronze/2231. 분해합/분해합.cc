#include <iostream>
#include <string>

using namespace std;

int N;
int length;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  string input;
  cin >> input;
  length = input.size();
  int num = stoi(input);

  for (int i = num - (9 * length); i < num; i++) {
    int tmp = 0;
    string number = to_string(i);

    for (int j = 0; j < number.size(); j++) {
      tmp += (number.at(j) - '0');
    }
    tmp += i;

    if (tmp == num) {
      cout << i;
      return 0;
    }
  }
  cout << "0";
}