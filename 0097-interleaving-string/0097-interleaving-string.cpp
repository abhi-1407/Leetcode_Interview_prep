class Solution {
    bool helper(int i1,int i2,int i3,string s1,string s2,string s3,vector<vector<vector<int>>> &dp)
    {
        if(i3==s3.length())
        {
            if(i1==s1.length() && i2==s2.length())
                return true;
            else
                return false;
        }
        if(dp[i1][i2][i3]!=-1)
            return dp[i1][i2][i3];
        if(s1[i1]==s2[i2] && s1[i1]==s3[i3])
        {
            return dp[i1][i2][i3]=(helper(i1+1,i2,i3+1,s1,s2,s3,dp)||helper(i1,i2+1,i3+1,s1,s2,s3,dp));
        }
        if(s1[i1]==s3[i3])
        {
            return dp[i1][i2][i3]=helper(i1+1,i2,i3+1,s1,s2,s3,dp);
        }
        if(s2[i2]==s3[i3])
        {
            return dp[i1][i2][i3]=helper(i1,i2+1,i3+1,s1,s2,s3,dp);
        }
        return dp[i1][i2][i3]=false;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<vector<int>>> dp(s1.length()+1,vector<vector<int>>(s2.length()+1,vector<int>(s3.length()+1,-1)));
        return helper(0,0,0,s1,s2,s3,dp);
    }
};