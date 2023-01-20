class Solution {
    void helper(int index,vector<int> &temp,set<vector<int>> &ans,int prev,vector<int> &nums)
    {
        if(index==nums.size())
        {
            if(temp.size()>=2)
            {
                ans.insert(temp);
                return;
            }
            return;
        }
              
        if(prev==-101 || prev<=nums[index])
        {
            temp.push_back(nums[index]);
            helper(index+1,temp,ans,nums[index],nums);
            temp.pop_back();
        }  
        helper(index+1,temp,ans,prev,nums);        
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> temp;
        helper(0,temp,ans,-101,nums);//prev has been set to -101 as a no can be as low as -100, so 
        return vector(ans.begin(),ans.end());
    }
};