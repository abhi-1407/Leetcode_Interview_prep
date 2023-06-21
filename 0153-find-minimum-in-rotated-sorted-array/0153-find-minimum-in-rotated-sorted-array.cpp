class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size(),l=0,h=n-1,ans=INT_MAX;
        if(nums[l]<nums[h])
            return nums[l];
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(nums[l]<=nums[mid])//left part is sorted and smallest element is nums[l]
            {
                ans=min(ans,nums[l]);
                l=mid+1;//lets search in the right
            }
            else //right part is sorted and smallest element is nums[mid]
            {
                ans=min(nums[mid],ans);
                h=mid-1;//lets search in the left
            }
            
        }
        return ans;
    }
};