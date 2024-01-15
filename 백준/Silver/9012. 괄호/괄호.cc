#include <iostream>
#include <stack>

using namespace std;

int main() {
    int test_case;

    cin >> test_case;

    for(int i = 0; i < test_case; i++) {
        stack<char> c;
        string input;
        bool flag = false;

        cin >> input;

        for(int j = 0; j < input.size(); j++) {
            if (input.at(j) == '(') {
                c.push('(');
            } else if (input.at(j) == ')') {
                if (c.empty()) {
                    flag = true;
                    break;
                }
                c.pop();
            }
        }

        if (c.empty() && !flag) {
            cout <<"YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}