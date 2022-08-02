class Solution {
        int lcs(string s1,string s2)
    {
        int m=s1.length();
        int n=s2.length();
        int dp[m+1][n+1];
        for(int i=0;i<m+1;i++)
        {
            for(int j=0;j<n+1;j++)
            {
                if(i==0 || j==0)
                {
                    dp[i][j]=0;
                }
                else if(s1[i-1]==s2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else 
                {
                    int call1=dp[i-1][j];
                    int call2=dp[i][j-1];
                    dp[i][j]=max(call1,call2);
                }
            }
        }
        return dp[m][n];
    }
public:
    int minInsertions(string s) {
        string s1=s;
        string s2=s;
        reverse(s2.begin(),s2.end());
        int ans=lcs(s1,s2);
        return s1.length()-ans;
    }
};