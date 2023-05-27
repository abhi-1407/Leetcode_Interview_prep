class Solution {
    int helper(int index,vector<int>& stoneValue,vector<int> &dp)
    {
        if(index>=stoneValue.size())
            return 0;
        if(dp[index]!=-1)
            return dp[index];
        int res=-1e9;
        int sum=0;
        for(int j=1;j+index<=stoneValue.size() && j<=3;j++)
        {
            sum+=stoneValue[j+index-1];
            res=max(res,sum-helper(j+index,stoneValue,dp));
        }
        return dp[index]=res;
    }
public:
    string stoneGameIII(vector<int>& stoneValue) {
      vector<int> dp(stoneValue.size(),-1);
      int ans=helper(0,stoneValue,dp);
      return ans>=0?(ans==0?"Tie":"Alice"):"Bob";
    }
};