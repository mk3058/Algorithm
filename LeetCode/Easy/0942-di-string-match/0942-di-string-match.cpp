class Solution {
public:
    vector<int> diStringMatch(string s) {
        int min = 0, max = s.length();
        vector<int> perm;
        
        for(int i = 0; i < s.length(); i++) {
            if (s[i] == 'I') {
                perm.push_back(min++);
            } else {
                perm.push_back(max--);
            }
        }
        perm.push_back(max);
        
        return perm;
    }
};