class Solution {
public:
    int countSubstrings(string s) {
    vector<vector<int>> dp(s.length(),vector<int>(s.length()));
    int count=0;
    for(int gap=0;gap<s.length();gap++)
    {
        for(int i=0,j=i+gap;i<s.length() && j<s.length();i++,j++)
        {
            if(gap==0)
            {
                dp[i][j]=1;
            }
            else if(gap==1)
            {
                if(s[i]==s[j])
                    dp[i][j]=1;
                else 
                    dp[i][j]=0;
            }
            else 
            {
                if(s[i]==s[j] && dp[i+1][j-1]==1)
                    dp[i][j]=1;
                else
                    dp[i][j]=0;
            }
            if(dp[i][j]==1)
                count++;
        }
        
    }
        return count;
    }
};