class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
     int n=nums2.size();
     unordered_map<int,int> nge;
     stack<int> st;
     for(int i=n-1;i>=0;i--)
     {
         int ele=nums2[i];
         while(st.size() > 0 and st.top() < ele )
         {
           st.pop();
         }
         if(st.empty())
         {
            nge[nums2[i]]=-1;
            st.push(nums2[i]);                 
         }
         else
         {
            nge[nums2[i]]=st.top();
            st.push(nums2[i]);
         }
     }
     vector<int> ans;
     for(int i=0;i<nums1.size();i++)
     {
         ans.push_back(nge[nums1[i]]);
     }
        return ans;
    }
};