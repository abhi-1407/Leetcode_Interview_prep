class Solution {
    int helper(vector<int> &satisfaction,int index,int time,vector<vector<int>> &dp)
    {
        if(index>=satisfaction.size())
        {
           return 0;
        }
        if(dp[index][time]!=-1)
            return dp[index][time];
        int pick=(satisfaction[index]*time)+helper(satisfaction,index+1,time+1,dp);
        int notpick=helper(satisfaction,index+1,time,dp);
        return dp[index][time]=max(pick,notpick);
    }
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int n=satisfaction.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return helper(satisfaction,0,1,dp);
    }
};