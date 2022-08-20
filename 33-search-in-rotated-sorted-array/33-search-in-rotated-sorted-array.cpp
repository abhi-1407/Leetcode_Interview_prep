class Solution {
    int pivot(vector<int>& nums)
    {
        int s=0;
        int e=nums.size()-1;
        while(s<e)
        {
            int mid=s+(e-s)/2;
            if(nums[mid]>=nums[0])
                s=mid+1;
            else
                e=mid;
        }
        return s;
    }
    int binarySearch(vector<int> nums,int s,int e,int target)
    {
        while(s<=e)
            {
                int mid=s+(e-s)/2;
                if(nums[mid]==target)
                   return mid;
                else if(nums[mid]<target)
                    s=mid+1;
                else
                    e=mid-1;
            }
            return -1;
    } 
public:
    int search(vector<int>& nums, int target) {
        
        int p=pivot(nums);        
        if(target >=nums[p] and target<=nums[nums.size()-1])//second line
        {
           return  binarySearch(nums,p,nums.size()-1,target);        
        }  
        
        else//present on the first line
        {
            return binarySearch(nums,0,p-1,target);
        }        
        
        
   }
};