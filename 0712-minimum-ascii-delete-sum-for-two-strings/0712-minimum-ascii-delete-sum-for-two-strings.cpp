class Solution {
    int helper(int index1,int index2,string &s1,string &s2,vector<vector<int>> &dp)
    {
        if(index1<0 && index2<0)
        {
            return 0;
        }
        else if(index1<0)
        {
            int sum=0;
            for(int i=index2;i>=0;i--)
            {
                sum+=(int)s2[i];
            }
            return sum;
        }
        else if(index2<0)
        {
            int sum=0;
            for(int i=index1;i>=0;i--)
            {
                sum+=(int)s1[i];
            }
            return sum;
        }
        if(dp[index1][index2]!=-1)
            return dp[index1][index2];
        int ans=0;
        if(s1[index1]==s2[index2])
        {
            ans=helper(index1-1,index2-1,s1,s2,dp);
        }
        else
        {
            ans=min((int)s1[index1]+helper(index1-1,index2,s1,s2,dp),(int)s2[index2]+helper(index1,index2-1,s1,s2,dp));
        }
        return dp[index1][index2]=ans;
    }

    public:
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.length(),m=s2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return helper(n-1,m-1,s1,s2,dp);
    }
};