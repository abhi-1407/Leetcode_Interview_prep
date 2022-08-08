class Solution {
    //Memoized
    int r(vector<int>& nums,int index,int prev,vector<vector<int>>&dp)
    {
        if(index==nums.size())//if index has crossed the size of the array then return 0
        {
            return 0;
        }
        if(dp[index][prev+1]!=-1)//if the state has been visited previously then return -1
            return dp[index][prev+1];
        int pick=0;
        int notpick=r(nums,index+1,prev,dp);//we can simple move to the next index without picking
        if((prev==-1)||(nums[index]>nums[prev]))//so that first one can be picked,prev==-1 should be written first,else it will call for nums[-1],which is out of bound
        pick=1+r(nums,index+1,index,dp);
        return dp[index][prev+1]=max(pick,notpick);
    }
    
   
    int DPP(vector<int>& nums,int n)
    {
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int index=n-1;index>=0;index--)
        {
            for(int prev=index-1;prev>=-1;prev--)
            {
                int pick=0;
                int notpick=dp[index+1][prev+1];
                if((prev==-1)||(nums[index]>nums[prev]))
                {
                    pick=1+dp[index+1][index+1];
                }
                dp[index][prev+1]=max(pick,notpick);
            }
        }
        return dp[0][0];
    }
    
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        //vector<vector<int>>dp(n,vector<int>(n,-1));
        //return r(nums,0,-1,dp);
        return DPP(nums,n);
        
    }
};