class Solution {
    int helper(int index,vector<vector<int>> &offers,vector<int> &dp)
    {
        if(index>=offers.size())
            return 0;
        if(dp[index]!=-1)
            return dp[index];
        int take=0;
        // for(int i=index+1;i<offers.size();i++)
        // {
        //     if(offers[i][0]>offers[index][1])
        //         take=max(take,helper(i,offers,dp)+offers[index][2]);
        // }
        int l=index+1,r=offers.size()-1,ans=offers.size();
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(offers[mid][0]>offers[index][1])
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        take=helper(ans,offers,dp)+offers[index][2];
        int nottake=helper(index+1,offers,dp);
        return dp[index]=max(take,nottake);
    }
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(offers.begin(),offers.end());
        vector<int> dp(offers.size()+1,-1);
        return helper(0,offers,dp);
        
    }
};