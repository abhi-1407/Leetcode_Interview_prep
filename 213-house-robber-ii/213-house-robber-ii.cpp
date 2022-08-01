class Solution {
     int helper(vector<int> nums,int n)
    {
        vector<int>dp(n,0);
        dp[0]=nums[0];
                  
        for(int i=1;i<n;i++)
        {
            int pick=nums[i];
            if(i>1)
            {
                pick+=dp[i-2];
            }
            int notpick=0+dp[i-1];
            dp[i]=max(pick,notpick);
                          
        }
        return dp[n-1];
    }
public:
    int rob(vector<int>& nums)
    {
        int n=nums.size();
        if(n==1)
        {
            return nums[0];
        }
        vector<int> temp1,temp2;
        for(int i=0;i<n-1;i++)
        {
            temp1.push_back(nums[i]);
        }
        for(int i=1;i<n;i++)
        {
            temp2.push_back(nums[i]);
        }
        
        return max(helper(temp1,n-1),helper(temp2,n-1));
        
    }
};