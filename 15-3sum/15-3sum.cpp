class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int> mpp;
        set<pair<pair<int,int>,int>> s;
        vector<vector<int>>  ans;
        for(int i=0;i<nums.size();i++)
        {
            mpp[nums[i]]=i;
        }
        vector<vector<int>> v;
        for(int i=0;i<nums.size()-2;i++)
        {
            for(int j=i+1;j<nums.size()-1;j++)
            {
                int CurrSum=nums[i]+nums[j];
                if((mpp.find(-CurrSum)!=mpp.end())&& (mpp[-CurrSum]>i) && (mpp[-CurrSum]>j))
                {
                    s.insert({{nums[i],nums[j]},nums[mpp[-CurrSum]]});
                }
            }
           
        }    
    
     for(auto it:s)
     {
         int a=it.first.first;
         int b=it.first.second;
         int c=it.second;
         vector<int> temp;
         temp.push_back(a);
         temp.push_back(b);
         temp.push_back(c);
         ans.push_back(temp);
     }
     return ans;
}
};