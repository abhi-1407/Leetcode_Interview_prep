class Solution {
    int helper(vector<int> &satisfaction,int index,int &prev,int time,vector<vector<int>> &dp)
    {
        if(index==satisfaction.size()-1)
        {
            return prev+max(0,satisfaction[index])*time;
        }
        if(dp[index][time]!=-1)
            return dp[index][time];
        int pick=(satisfaction[index]*time)+helper(satisfaction,index+1,prev,time+1,dp);
        int notpick=helper(satisfaction,index+1,prev,time,dp);
        return dp[index][time]=max(pick,notpick);
    }
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int n=satisfaction.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int prev=0;
        return helper(satisfaction,0,prev,1,dp);
    }
};