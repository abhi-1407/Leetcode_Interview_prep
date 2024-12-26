class Solution {
    int helper(vector<vector<int>> &dp,vector<int>& nums,int index,int &target){
        if(index == nums.size()){
            if(target == 0){
                return 1;
            }
            return 0;
        }
        if(dp[index][target + 1001]!=-1)
            return dp[index][target + 1001];
        target -= nums[index];
        int plus = helper(dp,nums,index + 1,target);
        target += nums[index];
        target += nums[index];
        int minus = helper(dp,nums,index + 1,target);
        target -= nums[index];
        return dp[index][target + 1001] = plus + minus;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(3000,-1));
        return helper(dp,nums,0,target);
    }
};