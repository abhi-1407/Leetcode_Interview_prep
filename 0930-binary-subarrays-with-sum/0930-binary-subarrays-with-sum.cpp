class Solution {
    int helper(vector<int> &nums,int goal)
    {
        if(goal<0)
            return 0;
        int i=0,j=0,sum=0,count=0;
        while(j<nums.size())
        {
            sum+=nums[j];
            while(sum>goal)
            {
                sum-=nums[i];
                i++;
            }
            count+=j-i+1;
            j++;
        }
        return count;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return helper(nums,goal)-helper(nums,goal-1);
    }
};