class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
     vector<int> v1;
     int i,j;
     i=0;
     j=0;
    for(int i=0;i<nums1.size();i++)
    {
        for(int j=0;j<nums2.size();j++)
       {
        if(nums1[i]==nums2[j])
         v1.push_back(nums1[i]);
          
        }
        
    }
    std::sort(v1.begin(), v1.end());
    v1.erase(std::unique(v1.begin(), v1.end()), v1.end());  
    return v1;   
    }
};