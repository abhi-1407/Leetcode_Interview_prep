class Solution {
    int helper(vector<pair<int,int>> &s,int index,int m,int n,vector<vector<vector<int>>> &dp)
    {
       if(index<0)
       {
           return 0;
       }
       if(m==0 && n==0) return 0; 
       if(dp[index][m][n]!=-1)
           return dp[index][m][n];
       int ones=0,zeros=0;
       zeros=s[index].first;
       ones=s[index].second;
       int pick=INT_MIN;
       if(m>=zeros and n>=ones)
       pick=1+helper(s,index-1,m-zeros,n-ones,dp);
       int notpick=helper(s,index-1,m,n,dp);
       return dp[index][m][n]=max(pick,notpick);
       
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>> s;
        vector<vector<vector<int>>> dp(strs.size(),vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        for(auto it:strs)
       {
           int zeros=0,ones=0;
           for(auto i:it)
           {
               if(i=='0')
                   zeros++;
               else
                   ones++;
           }
           s.push_back({zeros,ones});
       }
        return helper(s,s.size()-1,m,n,dp);
    }
};