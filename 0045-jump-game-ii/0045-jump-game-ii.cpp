class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps=0,i=0,j=0;
        while(j<nums.size()-1)
        {
            int maxd=0;
            for(int in=i;in<=j;in++)
            {
                maxd=max(maxd,in+nums[in]);
            }
            i=j+1;
            j=maxd;
            jumps++;
        }
        return jumps;
        
    }
};