class Solution{
void helper(vector<int>& nums,set<vector<int>> &s,int index,vector<int> temp)
    {
        if(index >=nums.size())
        {
            s.insert(temp);
            return;
        }
        temp.push_back(nums[index]);
        helper(nums,s,index+1,temp);
        temp.pop_back();
        helper(nums,s,index+1,temp);
    }
    
public:
    vector<vector<int>>subsetsWithDup(vector<int>& nums){
        set<vector<int>> s;
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        helper(nums,s,0,temp);
        for(auto it: s)
        {
            ans.push_back(it);
        }
        return ans;
    }
};