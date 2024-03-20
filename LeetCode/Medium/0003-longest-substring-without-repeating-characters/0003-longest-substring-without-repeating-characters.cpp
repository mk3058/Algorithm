class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length = 0;

        for(int i = 0; i < s.length(); i++) {
            int check[256] = {};
            int j;
            for(j = i; j < s.length(); j++) {
                if (check[s[j]]) {
                    break;
                }
                check[s[j]] = 1;
            }
            if (j - i > length) {
                length = j - i;
            }
        }
        return length;
    }
};