class Solution {
    bool helper(vector<int> &nums,int index,vector<int> &dp)
    {
        if(index==nums.size())
            return true;
        if(dp[index]!=-1)
            return dp[index];
        bool flag=false;
        if(index+1<nums.size())
        {
            if(nums[index]==nums[index+1])
                flag=flag|(helper(nums,index+2,dp));
        }
        if(index+2<nums.size())
        {
            if(nums[index]==nums[index+1] && nums[index+1]==nums[index+2])
                flag=flag|(helper(nums,index+3,dp));
            else if(nums[index]+1==nums[index+1] && nums[index+1]+1==nums[index+2])
                flag=flag|(helper(nums,index+3,dp));
        }
        return dp[index]=flag;
    }
public:
    bool validPartition(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return helper(nums,0,dp);
    }
};