class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        for(int stair = 2; stair < cost.size(); stair++) {
            int cost1 = cost[stair - 2] + cost[stair];
            int cost2 = cost[stair - 1] + cost[stair];
            
            cost[stair] = min(cost1, cost2);
        }
        
        return min(cost[cost.size() - 1], cost[cost.size() - 2]);
    }
};