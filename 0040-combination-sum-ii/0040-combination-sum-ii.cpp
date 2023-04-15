class Solution {
    void helper(vector<int> &candidates,int target,int index,vector<int> &temp,vector<vector<int>> &ans)
    {
        if(target==0)
            {
                ans.push_back(temp);
            return;
            }
        if(target<0)
            return ;
            
        for(int i=index;i<candidates.size();i++)
        {
            if(i>index && candidates[i-1]==candidates[i])
                continue;
            if(candidates[i]>target)
                break;
            else
            {
                temp.push_back(candidates[i]);
                helper(candidates,target-candidates[i],i+1,temp,ans);
                temp.pop_back();
            }
            
        }
        //helper(candidates,target,index+1,temp,ans);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> temp;
        vector<vector<int>> ans;
        helper(candidates,target,0,temp,ans);
        return ans;
    }
};