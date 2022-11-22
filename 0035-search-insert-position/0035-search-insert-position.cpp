class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums[0]>target)
            return 0;
        if(nums[nums.size()-1]<target)
            return nums.size();
        int low=0,high=nums.size()-1,ans;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid]<target)
            {
                low=mid+1;
            }
            else 
            {
                ans=mid;
                high=mid-1;
            }
        }
        return ans;
    }
};