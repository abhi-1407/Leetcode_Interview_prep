class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size()<3)
            return false;
        int left=INT_MAX,mid=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>left and nums[i]<mid)//if we find an element greater than left but less than mid then update the mid
                mid=nums[i];
            if(nums[i]<left)//if we find an element smaller than left then update left
                left=nums[i];
            if(nums[i]>mid and nums[i]>left)//if we find an element greater than mid and left then  we have found a subsequence
                return true;
        }
        return false;
       
        
    }
};