class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string res = "";
        vector<string> words;
        
        while (!ss.eof()) {
            string word;
            ss >> word;
            if (!word.empty())
                words.push_back(word);
        }
        
        for(int i = words.size() - 1; i >= 0; i--) {
            res += (words[i]);
            if (i != 0) {
                res += " ";
            }
        }
        return res;
    }
};