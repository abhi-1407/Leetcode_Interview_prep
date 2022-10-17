class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int count=0,sum=0;
        for(auto it:nums)
        {
            sum+=it;
            if(sum==k)
            count++;
            if(mpp.find(sum-k)!=mpp.end())
            {
                count+=mpp[sum-k];
            }
            
            mpp[sum]++;
        }
        return count;
        
    }
};