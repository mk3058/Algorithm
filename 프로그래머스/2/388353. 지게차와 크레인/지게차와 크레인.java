import java.util.*;

class Solution {
    
    public int solution(String[] s, String[] requests) {
        char[][] storage = new char[s.length][s[0].length()];
        
        int ti = 0;
        for(String tmp : s) {
            storage[ti++] = tmp.toCharArray();
        }
        
        for(String request : requests) {
            if(request.length() == 1) {
                lift(storage, request.charAt(0));
            } else {
                crain(storage, request.charAt(0));
            }
        }
        
        return countRemaining(storage);
    }
    
    public int countRemaining(char[][] storage) {
        int count = 0;
        for(int i = 0; i < storage.length; i++) {
            for(int j = 0; j < storage[0].length; j++) {
                if (storage[i][j] != 'n') count ++;
            }
        }
        return count;
    }
    
    public void lift(char[][] storage, char target) {
        List<Integer> x = new ArrayList<>();
        List<Integer> y = new ArrayList<>();
        
        for (int i = 0; i < storage.length; i++) {
            for (int j = 0; j < storage[0].length; j++) {
                if (storage[i][j] == target) {
                    boolean[][] isVisited = new boolean[storage.length][storage[0].length];
                    if (isAccessible(storage, isVisited, i, j)) {
                        x.add(i);
                        y.add(j);
                    }
                }
            }
        }
        
        for (int i = 0; i < x.size(); i++) {
            storage[x.get(i)][y.get(i)] = 'n';
        }
    }
    
    public void crain(char[][] storage, char target) {
        for(int i = 0; i < storage.length; i++) {
            for(int j = 0; j < storage[0].length; j++) {
                if (storage[i][j] == target) {
                    storage[i][j] = 'n';
                }
            }
        }
    }
    
    public boolean isAccessible(char[][] storage, boolean[][] isVisited, int x, int y) {
        if ((x == 0 || x == storage.length - 1 || y == 0 || y == storage[0].length - 1)) {
            return true;
        }
        
        isVisited[x][y] = true;
        
        int[] dx = {-1, 1, 0, 0};
        int[] dy = {0, 0, -1, 1};
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if ((nx >= 0 && nx <= storage.length - 1 && ny >= 0 && ny <= storage[0].length - 1)
                && storage[nx][ny] == 'n' && !isVisited[nx][ny]) {
                if (isAccessible(storage, isVisited, nx, ny)) {
                    return true;
                }
            }
        }
        return false;
    }
}