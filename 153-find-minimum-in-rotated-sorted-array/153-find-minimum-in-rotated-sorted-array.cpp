class Solution {
    
public:
    int findMin(vector<int>& nums) {
        int s=0;
        int e=nums.size()-1;
        int mid=s+(e-s)/2;
        while(s<e)
        {
            if(nums[mid]>=nums[0])
            {
                s=mid+1;
            }
            else
            {
                e=mid;
            }   
            mid=s+(e-s)/2;
        }
        // not we got our pivot element so we will compare with the 0th index value because that will be the minimum for the left part of the sorted elements
        if(nums[s] < nums[0]){
            return nums[s];
        }
        
        return nums[0];
        
    }
};