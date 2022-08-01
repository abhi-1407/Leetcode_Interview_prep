class Solution {
    bool helper(int index,vector<int> nums,int n)
    {
        
        if(index >= n-1)
            return true;
        if(nums[index]==0)
            return false;
        for(int i=1;i<=nums[index];i++)
        {
            if(helper(index+i,nums,n))
                return true;
        }
        
        return false;
    }
    
    bool dpSol(vector<int> nums,int n)
    {
        bool dp[n];
        for(int i=n-1;i>=0;i--)
        {
            if(i==n-1)
                dp[i]=true;
            else if(nums[i]==0)
                dp[i]=false;
            else
            {
                bool flag=true;
                for(int j=1;j<=nums[i];j++)
                {
                    
                    if(dp[i+j])
                    {
                        dp[i]=true;
                        flag=false;
                        break;
                    }
                }
                if(flag)
                    dp[i]=false;
                
                
            }
        }
        return dp[0];
    }
public:
    bool canJump(vector<int>& nums) {
        return dpSol(nums,nums.size());
    }
};