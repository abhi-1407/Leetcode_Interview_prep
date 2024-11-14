class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long count=0,n=nums.size();
        sort(nums.begin(),nums.end());
        for(long long index1=0;index1<n;index1++)
        {
            long long index2=lower_bound(nums.begin()+index1+1,nums.end(),lower-nums[index1])-nums.begin();
            long long index3=upper_bound(nums.begin()+index1+1,nums.end(),upper-nums[index1])-nums.begin()-1;
            if(index2<=index3)
            {
                count+=index3-index2+1;
            }
        }
        return count;
    }
};