class Solution {
public:
    int tribonacci(int n) {
        int tribonacci[3] = {0, 1, 1};

        for(int i = 3; i <= n; i++) {
            tribonacci[i % 3] = tribonacci[(i - 3) % 3] + tribonacci[(i - 2) % 3] + tribonacci[(i - 1) % 3];
        }
        return tribonacci[n % 3];
    }
};