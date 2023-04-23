class Solution {
public:
    int minOperations(vector<int>& nums) {
        int operations=0;
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
                count++;
        }
        if(count>0)
        return nums.size()-count;
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            int g=nums[i];
            for(int j=i+1;j<nums.size();j++)
            {
                g=__gcd(g,nums[j]);
                if(g==1)
                {
                    ans=min(ans,j-i+1);
                    break;
                }
            }
        }
        return ans==INT_MAX?-1:(nums.size()-1+ans-1);
    }
};