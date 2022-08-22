class Solution {
public:
    int jump(vector<int>& nums) {
        int curr=0,maxdist=0,jumps=0;
        for(int i=0;i<nums.size()-1;i++)
        {
           maxdist=max(maxdist,i+nums[i]);
           if(i==curr)
           {
               curr=maxdist;
               jumps++;
               
           }
        }
        return jumps;
        
    }
};