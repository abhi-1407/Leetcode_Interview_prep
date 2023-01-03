class Solution {
    bool isPossible(vector<int> &nums,int threshold,int div)
    {
        int sum=0;
        for(auto it:nums)
        {
            
            if(it%div==0)
                sum+=it/div;
            else
                sum+=(it/div)+1;
        }
        return sum<=threshold;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        sort(nums.begin(),nums.end());
        int ans;
        int low=1,high=nums[nums.size()-1];
        while(low<=high)
        {
            int mid=low+((high-low)>>1);
            if(isPossible(nums,threshold,mid))
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
};