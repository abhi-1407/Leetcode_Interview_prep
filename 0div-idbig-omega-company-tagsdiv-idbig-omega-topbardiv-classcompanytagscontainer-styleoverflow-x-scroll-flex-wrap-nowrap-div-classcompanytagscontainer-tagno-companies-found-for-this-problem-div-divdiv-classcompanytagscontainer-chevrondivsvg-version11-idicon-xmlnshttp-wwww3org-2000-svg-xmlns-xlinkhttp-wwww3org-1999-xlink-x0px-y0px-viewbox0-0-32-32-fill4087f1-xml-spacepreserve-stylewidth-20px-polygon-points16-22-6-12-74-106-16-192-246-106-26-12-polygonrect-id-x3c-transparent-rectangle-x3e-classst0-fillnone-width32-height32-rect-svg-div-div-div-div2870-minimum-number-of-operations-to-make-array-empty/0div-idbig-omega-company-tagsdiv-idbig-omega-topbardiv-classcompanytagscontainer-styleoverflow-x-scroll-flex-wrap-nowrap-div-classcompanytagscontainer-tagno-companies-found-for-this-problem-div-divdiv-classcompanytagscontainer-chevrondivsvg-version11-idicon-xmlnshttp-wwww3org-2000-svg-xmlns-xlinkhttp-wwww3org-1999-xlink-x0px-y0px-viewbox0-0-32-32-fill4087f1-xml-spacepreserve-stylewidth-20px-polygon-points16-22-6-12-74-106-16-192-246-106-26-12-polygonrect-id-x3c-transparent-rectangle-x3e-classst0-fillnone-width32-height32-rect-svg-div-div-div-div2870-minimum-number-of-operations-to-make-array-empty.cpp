class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(auto it:nums)
        {
            mpp[it]++;
        }
        int count=0;
        for(auto it:mpp)
        {
            if(it.second==1)
                return -1;
            else if(it.second%3==0)
                count+=it.second/3;
            else 
                count+=it.second/3+1;
        }
        return count;
    }
};