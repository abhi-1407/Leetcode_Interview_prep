class Solution {
    string helperDP(string s)
    {
        int n=s.length();        
        vector<vector<int>> dp(n,vector<int>(n,0));
        int maxLength=0;
        string ans="";
        for(int diff=0;diff<n;diff++)
        {
           for(int i=0,j=diff+i;i<n &&j<n;j++,i++)
           {
               if(i==j)
               {
                   dp[i][j]=1;
               }
               else if((j-i)==1)
               {
                   if(s[i]==s[j])
                       dp[i][j]=2;
                   else
                       dp[i][j]=0;
               }
               else 
               {
                   if(s[i]==s[j] && dp[i+1][j-1])
                       dp[i][j]=dp[i+1][j-1]+2;
               }
               if(dp[i][j])//if entry is not 0
               {
                   if(j-i+1>maxLength)//compare and see if the maxLength is greater
                   {
                       maxLength=j-i+1;//update it
                      ans=s.substr(i,maxLength);//update ans
                   }
               }
           }
        }
       return ans;
    }
public:
    string longestPalindrome(string s) {
        
        return  helperDP(s);
    }     
        
};