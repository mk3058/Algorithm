class Solution {
    public int[] solution(String[] wallpaper) {
        int left = 51, right = -1, top = 51, bottom = -1;
        
        for(int i = 0; i < wallpaper.length; i++) {
            for(int j = 0; j < wallpaper[i].length(); j++) {
                if (wallpaper[i].charAt(j) == '#') {
                    if (j < left) left = j;
                    if (j > right) right = j;
                    if (i < top) top = i;
                    if (i > bottom) bottom = i;
                }
            }
        }
        
        return new int[]{top, left, bottom + 1, right + 1};
    }
}