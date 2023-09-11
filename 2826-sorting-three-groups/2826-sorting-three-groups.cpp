class Solution {
    int helper(int index,int prev,vector<int> &nums,vector<vector<int>> &dp)
    {
        if(index==nums.size())
            return 0;
        if(dp[index][prev]!=-1)
            return dp[index][prev];
        int mini=INT_MAX;
        int curr=nums[index];
        for(int i=prev;i<=3;i++)
        {
            int ans=helper(index+1,i,nums,dp);
            if(i!=curr)
                ans++;
            mini=min(ans,mini);
        }
        return dp[index][prev]=mini;
    }
public:
    int minimumOperations(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(4,-1));
        return helper(0,1,nums,dp);
    }
};