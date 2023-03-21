class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count=0,ans=0;
        for(long long i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
                count++;
            else
            {
                ans+=(count*(count+1))/2;
                count=0;
            }
        }
        if(count!=0)
            {
                ans+=(count*(count+1))/2;
                count=0;
            }
            
        return ans;
    }
};