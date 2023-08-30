class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        long long max_val=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            long long parts=ceil(nums[i]/(double)max_val);
            ans+=parts-1;
            max_val=nums[i]/parts;
        }
        return ans;
    }
};