class Solution {
    int isPossible(vector<int> &nums,int k,int limit)
    {
        int sum=0;
        int count=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>limit){
                count++;
                sum=nums[i];
            }
            if(count>k)
                return false;
        }
        return true;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int mini=*max_element(nums.begin(),nums.end()),ans=0;
        int maxi=accumulate(nums.begin(),nums.end(),0);
        while(mini<=maxi)
        {
            int mid=mini+(maxi-mini)/2;
            if(isPossible(nums,k,mid))
            {
                ans=mid;
                maxi=mid-1;
            }
            else
            {
                mini=mid+1;
            }
        }
        return ans;
    }
};
