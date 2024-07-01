class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        /** 세 값의 합이 0이 되는 조합 찾기
                - 세 값의 인덱스는 모두 달라야 함
                - 중복되는 조합은 존재하지 않아야 함
            - 주어진 수에 중복되는 수 존재
            - 주어진 수에 0도 포함

            - nums 순회하면서 현재 수 이외의 두수로 0이 되는거 있는지 찾기 (투포인터)
            - 조합 찾으면 정렬해서 정답 목록에 삽입
            - 조합은 set<vector<int>> 로 관리하여 중복 없도록 관리
        **/

        set<vector<int>> result;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++) {
            int l = i + 1; // 현재 수 이상에서 탐색
            int r = nums.size() - 1;
            while (l < r) {
                int negative = -nums[i];
                if (nums[l] + nums[r] == negative) {
                    result.insert({nums[i], nums[l], nums[r]});
                    l++;
                }
                else if (nums[l] + nums[r] < -nums[i]) l++;
                else r--;
            }
        }

        return vector(result.begin(), result.end());
    }
};