class Solution {
    int helper(vector<int> &cost,int index,vector<int> &dp)
    {
        if(index==0 || index==1)
            return cost[index];
        if(dp[index]!=-1)
            return dp[index];
        int one=helper(cost,index-1,dp);
        int two=helper(cost,index-2,dp);
        return dp[index]=min(one,two)+cost[index];
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(1001,-1);
        return min(helper(cost,n-1,dp),helper(cost,n-2,dp));
    }
};