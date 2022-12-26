class Solution {
//     bool helper(int index,vector<int> nums,int n)
//     {
        
//         if(index >= n-1)
//             return true;
//         if(nums[index]==0)
//             return false;
//         bool flag=false;
//         for(int i=1;i<=nums[index];i++)
//         {
//             if(helper(index+i,nums,n,dp))
//                 flag=true;
//         }
        
//         return false;
//     }
    
    bool dpSol(vector<int> nums,int n)
    {
        
        vector<bool> dp(1e5,false);        
        for(int index=n-1;index>=0;index--)
        {
            if(index==n-1)
                dp[index]=true;
            else if(nums[index]==0)
                dp[index]=false;
            bool flag=false;
            for(int i=1;i<=nums[index];i++)
            {
                if(dp[index+i])
                {
                    flag=true;
                    break;
                }
            }
            if(flag)
                dp[index]=true;
        }
        return dp[0];
        
    }
public:
    bool canJump(vector<int>& nums) {
        return dpSol(nums,nums.size());
    }
};