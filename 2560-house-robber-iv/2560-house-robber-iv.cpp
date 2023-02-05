class Solution {
    bool isPossible(vector<int>&nums,int value,int k)
    {
        int last_index=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>value)
                continue;
            else if(last_index+1==i)
                continue;
            else
            {
                last_index=i;
                k--;
            }
        }
        return (k<=0);
    }
public:
    int minCapability(vector<int>& nums, int k) {
        int start=0,end=1e9+1;
        while(start<end)
        {
            int mid=start+(end-start)/2;
            if(isPossible(nums,mid,k))
                end=mid;
            else
                start=mid+1;
        }
        return start;
    }
};