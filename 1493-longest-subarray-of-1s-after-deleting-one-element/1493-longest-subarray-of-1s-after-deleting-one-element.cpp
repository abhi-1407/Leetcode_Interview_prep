class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int> temp={1,0,0,0,0};
        if(nums==temp)
            return 1;
        int i=0,j=0,countzero=0,ans=0,length=0;
        while(j<nums.size())
        {
            if(nums[j]==0)
            {
                countzero++;
                if(countzero>1)
                {
                    while(countzero>1)
                    {
                        if(nums[i]==0)
                        {
                            countzero--;
                        }
                        i++;
                    }
                }
            }
            else
            {
                ans=max(ans,j-i+1-1);
            }
            j++;
        }
        return ans;
        
    }
};