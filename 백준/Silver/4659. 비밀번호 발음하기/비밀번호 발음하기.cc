#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    
    string vowel = "aeiou";

    while(true) {
        string input;
        bool isVowelContained = false;
        bool acceptable = true;

        cin >> input;
        if (!input.compare("end")) return 0;

        for(int i = 0; i < input.size(); i++) {
            if (vowel.find(input[i]) != string::npos) {
                isVowelContained = true;
            }
            
            if (i < 1) continue;
            if (input[i] == input[i - 1] && (input[i] != 'e' && input[i] != 'o')) {
                acceptable = false;
                break;
            } 

            if (i < 2) continue;
            if ((vowel.find(input[i]) != string::npos) == (vowel.find(input[i - 1]) != string::npos)) {
                if ((vowel.find(input[i]) != string::npos) == (vowel.find(input[i - 2]) != string::npos)) {
                acceptable = false;
                break;
                }
            }
        }

        if (acceptable && isVowelContained) {
            cout << "<" << input << ">" << " is acceptable." << endl;
        } else {
            cout << "<" << input << ">" << " is not acceptable." << endl;
        }
    }
}