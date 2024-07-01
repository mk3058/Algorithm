class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int idx1 = 0, idx2 = 0;
        string res = "";
        
        while (idx1 < word1.length() && idx2 < word2.length()) {
            res += word1.at(idx1++);
            res += word2.at(idx2++);
        }
        
        while (idx1 < word1.length()) {
            res += word1.at(idx1++);
        }
        while (idx2 < word2.length()) {
            res += word2.at(idx2++);
        }
        return res;
    }
};