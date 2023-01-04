class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if(nums.size()<3)
        return false;
        stack<pair<int,int>> st;
        st.push({nums[0],nums[0]});
        int currMin=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            int curr=nums[i];
            while(!st.empty() && curr>=st.top().first)
            {
                st.pop();
            }
            if(!st.empty() && curr<st.top().first && curr>st.top().second)
            {
                return true;
            }
            currMin=min(currMin,nums[i]);
            st.push({nums[i],currMin});            
        }
        return false;
    }
};