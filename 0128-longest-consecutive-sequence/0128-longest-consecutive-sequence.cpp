class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        int maxcount=0;
        for(int i=0;i<nums.size();i++)
        {
            if(s.find(nums[i]-1)!=s.end())
                continue;
            else
            {
                int index=1;
                while(s.find(nums[i]+index)!=s.end())
                {
                    index++;
                }
                maxcount=max(index,maxcount);
            }
        }
        return maxcount;
    }
};