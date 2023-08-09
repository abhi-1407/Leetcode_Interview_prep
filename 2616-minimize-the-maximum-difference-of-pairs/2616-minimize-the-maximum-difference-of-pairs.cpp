class Solution {
    bool helper(vector<int>&nums,int mid,int p)
    {
        int count=0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]-nums[i-1]<=mid)
            {
                count++;
                i++;
            }
        }
        return count>=p;
    }
public:
    int minimizeMax(vector<int>& nums, int p) {
        int n=nums.size(),ans=-1;
        sort(nums.begin(),nums.end());
        int low=0,high=nums[nums.size()-1];
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(helper(nums,mid,p))
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
