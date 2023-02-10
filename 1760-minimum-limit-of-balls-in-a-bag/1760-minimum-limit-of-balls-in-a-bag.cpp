class Solution {
    bool isPossible(int capacity,vector<int> &nums,int max)
    {
        int operations=0;
        for(auto it:nums)
        {
            operations+=((it%capacity)==0)?((it/capacity)-1):(it/capacity);
        }
        return (int)operations<=max;
    }
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low=1,high=*max_element(nums.begin(),nums.end()),ans=0;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(isPossible(mid,nums,maxOperations))
            {
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    }
};