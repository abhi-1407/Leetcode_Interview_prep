class Solution {
    string helper(string s1,string s2)
    {
        int m=s1.length();
        int n=s2.length();
        int dp[m+1][n+1];
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0 || j==0)
                    dp[i][j]=0;
                else if(s1[i-1]==s2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        string s="";
        int i=m,j=n;
        while(i>0 && j>0)
        {
            if(s1[i-1]==s2[j-1])
            {
                s+=s1[i-1];
                i--;
                j--;
            } 
            else if(dp[i-1][j]>=dp[i][j])
            {
                s+=s1[i-1];
                i--;
                
            }
            else
            {
                s+=s2[j-1];
                j--;
            }
        }
        while(j>0)
        {
            s+=s2[j-1];
            j--;
        }
        while(i>0)
        {
            s+=s1[i-1];
            i--;
        }
        reverse(s.begin(),s.end());
        return s;
        
    }
public:
    string shortestCommonSupersequence(string str1, string str2) {        
        return helper(str1,str2);
    }
};