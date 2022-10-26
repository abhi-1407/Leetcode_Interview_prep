class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(sum%k==0 and i>0) //suppose subarray's size is less than 2 eg:[0] 1
                return true;
            if(mpp.count(sum%k) and (i-mpp[sum%k])>=2)
                return true;
            if(mpp.count(sum%k)==0)
                mpp[sum%k]=i;
        }
        return false;
    
    }
};