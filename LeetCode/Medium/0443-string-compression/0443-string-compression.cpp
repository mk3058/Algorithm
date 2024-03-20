class Solution {
public:
    int compress(vector<char>& chars) {
        int compressedStringIndex = 0, count = 0;
        char current;
        
        for(int i = 0; i < chars.size(); i++) {
            count = 1;
            current = chars[i];
            while (i + 1 < chars.size() && chars[i + 1] == current) {
                count++;
                i++;
            }
            if (count > 1) {
                string countString = to_string(count);
                chars[compressedStringIndex++] = current;
                for(int j = 0; j < countString.size(); j++) {
                    chars[compressedStringIndex++] = countString[j];
                }
            } else {
                chars[compressedStringIndex++] = current;
            }
        }
        return compressedStringIndex;
    }
};