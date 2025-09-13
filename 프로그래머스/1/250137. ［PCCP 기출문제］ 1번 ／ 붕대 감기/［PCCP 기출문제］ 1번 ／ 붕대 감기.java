class Solution {
    public int solution(int[] bandage, int health, int[][] attacks) {
        Integer currentHealth = health;
        Integer elapsed = -1;

        int ax = 0;
        for(int t = 0; t <= attacks[attacks.length - 1][0]; t++) {
            elapsed++;
            if (t == attacks[ax][0]) {
                currentHealth -= attacks[ax][1];
                elapsed = 0;
                ax++;
            } else {
                currentHealth += bandage[1];
                if (elapsed == bandage[0]) {
                    elapsed = 0;
                    currentHealth += bandage[2];
                }
            }
            currentHealth = Math.min(Math.max(currentHealth, 0), health);
            if (currentHealth == 0) {
                return -1;
            }
        }
        
        return currentHealth;
    }
}