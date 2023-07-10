class Solution {
    int helper(vector<int> &slices,int index,int last,int k,vector<vector<int>> &dp)
    {
        if(index>last || k==0)
            return 0;
        if(dp[index][k]!=-1)
            return dp[index][k];
        int pick=slices[index]+helper(slices,index+2,last,k-1,dp);
        int notpick=helper(slices,index+1,last,k,dp);
        return dp[index][k]=max(pick,notpick);
    }
        
public:
    int maxSizeSlices(vector<int>& slices) {
        int n=slices.size();
        vector<vector<int>> dp1(n,vector<int>(n/3+1,-1));
        int ans1=helper(slices,1,n-1,n/3,dp1);
        vector<vector<int>> dp2(n,vector<int>(n/3+1,-1));
        int ans2=helper(slices,0,n-2,n/3,dp2);
        return max(ans1,ans2);
    }
};