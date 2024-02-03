class Solution {
    int helper(vector<int> &arr,int index,int k,vector<int> &dp)
    {
        if(index==arr.size())
            return 0;
        if(dp[index]!=-1)
            return dp[index];
        int maxi=INT_MIN,maxAns=0;
        for(int length=0;length<k && length+index<arr.size();length++)
        {
            maxi=max(maxi,arr[length+index]);
            int sum=maxi*(length+1)+helper(arr,index+length+1,k,dp);
            maxAns=max(maxAns,sum);
        }
        return dp[index]=maxAns;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size()+1,-1);
        return helper(arr,0,k,dp);
    }
};