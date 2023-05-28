class Solution {
    int f(vector<int> &cuts,int i,int j,vector<vector<int>> &dp)
    {
        if(i>j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int mini=1e7;
        for(int ind=i;ind<=j;ind++)
        {
            int cost=(cuts[j+1]-cuts[i-1])+f(cuts,i,ind-1,dp)+f(cuts,ind+1,j,dp);
            mini=min(mini,cost);
        }
        return dp[i][j]=mini;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(cuts.size(),vector<int>(cuts.size(),-1));
        return f(cuts,1,cuts.size()-2,dp);
    }
};
