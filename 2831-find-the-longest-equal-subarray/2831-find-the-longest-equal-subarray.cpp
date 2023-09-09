class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int i=0,j=0,ans=0,maxi=0;
        while(j<nums.size())
        {
            mpp[nums[j]]++;
            maxi=max(maxi,mpp[nums[j]]);
            while((j-i+1)-maxi>k)
            {
                mpp[nums[i]]--;
                i++;
            }
            ans=max(ans,maxi);
            j++;
        }
        return ans;
    }
};