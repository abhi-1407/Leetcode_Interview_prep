class Solution {
    int helper(vector<int> &cost,int index,vector<int> &dp)
    {
        if(index==0 || index==1)
            return cost[index];
        if(dp[index]!=-1)
            return dp[index];
        int one=cost[index]+helper(cost,index-1,dp);
        int two=INT_MAX;
        if(index>=2)
        two=cost[index]+helper(cost,index-2,dp);
        return dp[index]=min(one,two);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(1001,-1);
        return min(helper(cost,n-1,dp),helper(cost,n-2,dp));
    }
};