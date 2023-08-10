class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        if(nums[0]==target)
            return true;
        if(nums[n-1]==target)
            return true;
        int i=1,j=n-2;
        while(i<=j)
        {
            int mid=i+(j-i)/2;
            if(nums[mid]==target)
                    return true;
            if(nums[mid]==nums[i] && nums[mid]==nums[j])
            {
                i++;
                j--;
                continue;
            }
            if(nums[i]<=nums[mid])
            {
                if(nums[i]<=target && target<=nums[mid])
                {
                    j=mid-1;
                }
                else
                {
                    i=mid+1;
                }
            }
            else
            {
                if(nums[mid]<=target && target<=nums[j])
                {
                    i=mid+1;
                }
                else
                {
                    j=mid-1;
                }
            }
        }
        return false;
    }
};