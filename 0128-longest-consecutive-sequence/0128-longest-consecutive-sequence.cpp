class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            st.insert(nums[i]);
        }
        for(int i=0;i<nums.size();i++)
        {
            if(st.find(nums[i]-1)==st.end())
            {
                int start=nums[i],count=0;
                while(st.find(start)!=st.end())
                {
                    count++;
                    start++;
                }
                maxi=max(maxi,count);
            }
        }
        return maxi==INT_MIN?0:maxi;
    }
};