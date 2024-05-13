class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n < 1) {
            return false;
        }
        double res = log(n) / log(4);

        if (res - (int)res < 0.000000000000001) {
            return true;
        }
        return false;
    }
};