class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        if (words.size() != s.length()) {
            return false;
        }
        
        for(int i = 0; i < words.size(); i++) {
            if (words[i].at(0) != s.at(i))
            {
                return false;
            }
        }
        return true;
    }
};