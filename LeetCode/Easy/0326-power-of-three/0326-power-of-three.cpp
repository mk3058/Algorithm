class Solution {
public:
    bool isPowerOfThree(int n) {
        long num = 1;

        return isPower(num, n);
    }

    bool isPower(long &num, int &target) {
        if (target == num) {
            return true;
        } else if (num > target) {
            return false;
        }

        num *= 3;
        return isPower(num, target);
    }
};
