import java.util.*;

class Solution {
    public int solution(int[] diffs, int[] times, long limit) {
        int li = 1, ri = 100000;
        int answer = ri;
        
        while (li <= ri) {
            int level = (li + ri) / 2;
            
            if (simulate(level, diffs, times) > limit) {
                li = level + 1;
            } else {
                answer = Math.min(level, answer);
                ri = level - 1;
            }
        }
        
        return answer;
    }
    
    public long simulate(int level, int[] diffs, int[] times) {
        long timeCur = times[0], timePrev = 0;
        long cumulativeTime = 0;
        
        if (diffs[0] > level) cumulativeTime += (timeCur + timePrev) * (diffs[0] - level) + timeCur;
        else cumulativeTime += timeCur;
        
        for(int i = 1; i < diffs.length; i++) {
            timeCur = times[i];
            timePrev = times[i - 1];
            
            if (diffs[i] > level) cumulativeTime += ((timeCur + timePrev) * (diffs[i] - level) + timeCur);
            else cumulativeTime += timeCur;
        }
        
        return cumulativeTime;
    }
}