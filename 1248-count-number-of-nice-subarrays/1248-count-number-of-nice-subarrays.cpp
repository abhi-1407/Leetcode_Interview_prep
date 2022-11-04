class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int i=0,j=0,count=0,ans=0,odd=0,n=nums.size();
        while(j<n)
        {
            if((nums[j]%2)!=0)   
            {
                odd++;
                count=0;
            }
            while(odd==k)
            {
               count++;
               if(nums[i++]%2!=0)
               odd--;              
            }
            ans+=count;
            j++;
       }
        return ans;
    }
};