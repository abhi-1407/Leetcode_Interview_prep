class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        unordered_map<long long,long long> mpp;
        long long count=0,cnt=0;
        mpp[0]=1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%modulo==k)
                cnt++;
            count+=mpp[(cnt-k)%modulo];
            mpp[cnt%modulo]++;
        }
        return count;
    }
};