class Solution {
//recursive solution gives TLE
// int helper(vector<int>& nums,int target,int n)
// {
//     if(target<0)
//         return 0;
//     if(target==0)
//         return 1;
//     int ans=0;
//     for(int i=0;i<nums.size();i++)
//     {
//         ans+=helper(nums,target-nums[i],n);
//     }
//     return ans;
// }
    
long int helperDP(vector<int> &nums,int t)
{
    unsigned int dp[t+1];
    for(int target=0;target<=t;target++)
    {
       if(target==0)
       {
         dp[target]=1;//base case
         continue;
       }
       unsigned int ans=0;//as the value can never be negative and "The test cases are generated so that the answer can fit in a 32-bit integer." so we can use unsigned int
       for(int i=0;i<nums.size();i++)
       {
            if(target-nums[i]>=0)
               ans+=dp[target-nums[i]];
       }
       dp[target]=ans;
    }
    return dp[t];
}
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        //return helper(nums,target,n);
        return helperDP(nums,target);
    }
};