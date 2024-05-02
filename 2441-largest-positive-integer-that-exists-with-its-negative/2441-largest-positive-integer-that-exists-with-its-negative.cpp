class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> st;
        int maxi=INT_MIN;
        for(auto it:nums)
            st.insert(it);
        for(auto it:nums)
        {
            if(it>0 && st.find(-1*it)!=st.end())
                maxi=max(maxi,it);
        }
        return maxi==INT_MIN?-1:maxi;
    }
};