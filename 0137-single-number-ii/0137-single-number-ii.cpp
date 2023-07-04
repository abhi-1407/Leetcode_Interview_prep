class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<32;i++)
        {
            int countone=0,countzero=0;
            for(auto it:nums)
            {
                int num=(it>>i)&1;
                if(num)
                {
                    countone++;
                }
                else
                {
                    countzero++;
                }
            }
            if(countone%3==1)
            {
                ans=ans|(1<<i);
            }
        }
        return ans;
    }
};