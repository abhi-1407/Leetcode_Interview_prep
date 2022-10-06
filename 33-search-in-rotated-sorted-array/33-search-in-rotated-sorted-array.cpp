class Solution {
/* There is a chance that the array is left sorted or right sorted */
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(nums[mid]==target)
            return mid;
            
            if(nums[l]<=nums[mid])//array is sorted in the left in ascending order
            {
                if(nums[l]<=target and target<=nums[mid])
                {
                    r=mid-1;
                }
                else
                {
                    l=mid+1;
                }
            }
            
            else 
            {
                if(nums[mid]<=target && target<=nums[r])
                {
                    l=mid+1;
                }
                else
                {
                    r=mid-1;
                }
            }
        }
        return -1;
    }
};