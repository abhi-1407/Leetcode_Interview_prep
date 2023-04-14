class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string s1=s;
        string s2=s;
        reverse(s2.begin(),s2.end());
        int n=s.length();
        vector<vector<int>> ans(n+1,vector<int>(n+1,0));
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0 || j==0)
                {
                    ans[i][j]=0;
                }
                else if(s1[i-1]==s2[j-1])
                {
                    ans[i][j]=1+ans[i-1][j-1];
                }
                else
                {
                    ans[i][j]=max(ans[i-1][j],ans[i][j-1]);
                }
            }
        }
        return ans[n][n];
    }
};