class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long long l=0,r=0,sum=0,ans=1;
        while(r<nums.size())
        {
            sum+=nums[r];
            while(((r-l+1)*nums[r]-sum)>k)
            {
                sum-=nums[l];
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};