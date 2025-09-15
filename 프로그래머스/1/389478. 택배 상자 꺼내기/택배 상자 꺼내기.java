class Solution {
    public int solution(int n, int w, int num) {
        return findUpBoxCount(num, n, w) + 1;
    }
    
    public int findRowOfTarget(int num, int w) {
        int row = (num / w);
        if (num % w != 0) row++;
        
        return row;
    }
    
    public int findColOfTarget(int num, int row, int w) {
        if (row % 2 == 0) {
            return row * w + 1 - num;
        } else {
            return num - (row - 1) * w; 
        }
    }
    
    public int findUpBoxCount(int num, int n, int w) {
        int targetRow = findRowOfTarget(num, w);
        int targetCol = findColOfTarget(num, targetRow, w);
        
        System.out.println("Row = " + targetRow + ", Col = " + targetCol);
        int count = 0;
        
        // for (int i = 0; i < 3; i++) {
        while(getBoxNumber(++targetRow, targetCol, w) <= n) {
            // System.out.println(getBoxNumber(targetRow, ++targetCol, w));
            count++;
        }
        
        return count;
    }
    
    public int getBoxNumber(int row, int col, int w) {
        if (row % 2 == 0) {
            return (row - 1) * w + (w - col) + 1;
        } else {
            return (row - 1) * w + col; 
        }
    }
}