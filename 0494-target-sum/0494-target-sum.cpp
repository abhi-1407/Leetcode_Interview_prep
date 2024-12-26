class Solution {
    int helper(int index,vector<int> &nums,int &sum,int target,vector<vector<int>> &dp)
    {
        if(index==nums.size())
        {
            if(sum==target)
                return 1;
            else
                return 0;
        }
        if(dp[index][sum+1001]!=-1)
            return dp[index][sum+1001];
        int plus=0,minus=0;
        sum+=nums[index];
        plus=helper(index+1,nums,sum,target,dp);
        sum-=nums[index];
        sum-=nums[index];
        minus=helper(index+1,nums,sum,target,dp);
        sum+=nums[index];
        return dp[index][sum+1001]=plus+minus;
    }
    
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        vector<vector<int>> dp(nums.size(),vector<int>(2002,-1));
        return helper(0,nums,sum,target,dp);
    }
};