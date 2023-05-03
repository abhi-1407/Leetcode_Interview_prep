class Solution {
    vector<int> helper(vector<int> &nums1,vector<int> &nums2)
    {
        unordered_set<int> st;
        vector<int> ans;
        for(auto it:nums1)
            st.insert(it);
        for(int i=0;i<nums2.size();i++)
        {
            if(st.find(nums2[i])!=st.end())
                st.erase(nums2[i]);
        }
        for(auto it:st)
            ans.push_back(it);
        return ans;
    }
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> fans;
        vector<int> ans1=helper(nums1,nums2);
        vector<int> ans2=helper(nums2,nums1);
        fans.push_back(ans1);
        fans.push_back(ans2);
        return fans;
    }
};