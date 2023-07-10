class Solution {
    int helper(int index,vector<int> &nums1,vector<int> &nums2,int swapped,vector<vector<int>> &dp)
    {
        if(index==nums1.size())
            return 0;
        if(dp[index][swapped]!=-1)
            return dp[index][swapped];
        int prev1=nums1[index-1];
        int prev2=nums2[index-1];

        if(swapped)
            swap(prev1,prev2);

        int ans=INT_MAX;
        //noswap
        if((nums1[index]>prev1 && nums2[index]>prev2))
        ans=helper(index+1,nums1,nums2,0,dp);
        
        //swap
        if(nums1[index]>prev2 && nums2[index]>prev1)
            ans=min(1+helper(index+1,nums1,nums2,1,dp),ans);
        return dp[index][swapped]=ans;
    }
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
        vector<vector<int>> dp(nums1.size(),vector<int>(2,-1));
        return helper(1,nums1,nums2,0,dp);
    }
};