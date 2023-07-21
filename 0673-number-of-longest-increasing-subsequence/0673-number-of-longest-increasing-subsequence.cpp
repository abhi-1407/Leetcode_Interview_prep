class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size(),maxi=INT_MIN;
        vector<int> count(n,1),dp(n,1);
        for(int index=0;index<nums.size();index++)
        {
            for(int prev=0;prev<index;prev++)
            {
                if(nums[index]>nums[prev] && dp[index]<dp[prev]+1)
                {
                    dp[index]=dp[prev]+1;
                    count[index]=count[prev];
                }
                else if(nums[index]>nums[prev] && dp[index]==dp[prev]+1)
                {
                    count[index]+=count[prev];
                }
            }
            maxi=max(maxi,dp[index]);
        }
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(dp[i]==maxi)
            {
                c+=count[i];
            }
        }
        return c;

    }
};

