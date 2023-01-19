class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int sum=0,count=0;
        mpp[0]=1;
        for(auto it:nums)
        {
            sum+=it;
            int rem=sum%k;
            if(rem<0)
                rem+=k;           
            if(mpp.find(rem)!=mpp.end())
            {
                count+=mpp[rem];
            } 
            mpp[rem]++;//put this after finding sum
        }
        return count;
    }
};