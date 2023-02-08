class Solution {
    int helper(int index1,int index2,string &s,string &t,vector<vector<int>> &dp)
    {
        if(index1==0 && index2-1>=0)
            return 0;
        if(index2==0)
            return 1;
        if(dp[index1][index2]!=-1)
            return dp[index1][index2];
        if(s[index1-1]==t[index2-1])
        {
            int pick=helper(index1-1,index2-1,s,t,dp);
            int notpick=helper(index1-1,index2,s,t,dp);//stay at that index as I am not matching
            return dp[index1][index2]=pick+notpick;
        }
        else
        {
            int notpick=helper(index1-1,index2,s,t,dp);
            return dp[index1][index2]=notpick;
        }
    }
public:
    int numDistinct(string s, string t) {
        int n=s.length(),m=t.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return helper(n,m,s,t,dp);
    }
};