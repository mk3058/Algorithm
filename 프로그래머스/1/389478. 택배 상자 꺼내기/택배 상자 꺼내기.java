class Solution {
    public int solution(int n, int w, int num) {
        int targetRow = findRowOfTarget(num, w);
        int targetCol = findColOfTarget(num, targetRow, w);
        int count = 0;
        
        while(getBoxNumber(++targetRow, targetCol, w) <= n) {
            count++;
        }
        
        return count + 1;
    }
    
    public int findRowOfTarget(int num, int w) {
        return num % w == 0 ? (num / w) : (num / w) + 1;
    }
    
    public int findColOfTarget(int num, int row, int w) {
        return row % 2 == 0 ? (row * w + 1 - num) : (num - (row - 1) * w);
    }
    
    public int getBoxNumber(int row, int col, int w) {
        return (row - 1) * w + (row % 2) * col + ((row + 1) % 2) * (w - col + 1);
    }
}