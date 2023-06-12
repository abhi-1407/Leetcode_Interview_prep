class Solution {
    int atmost(vector<int> &nums,int k)
    {
        unordered_map<int,int> mpp;
        int i=0,j=0,ans=0;
        while(j<nums.size())
        {
            mpp[nums[j]]++;
            while(mpp.size()>k)
            {
                mpp[nums[i]]--;
                if(mpp[nums[i]]==0)
                    mpp.erase(nums[i]);
                i++;
            }
            ans+=j-i+1;
            j++;
        }
        return ans;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
};