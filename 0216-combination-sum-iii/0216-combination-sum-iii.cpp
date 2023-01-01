class Solution {
private:
     void r(vector<int>& candidates, int target,vector<vector<int>> &ans,vector<int> &a,int index,int k)
     {
         if(index==candidates.size())
         {
             if(target==0 && a.size()==k)
             {
                 ans.push_back(a);           
             }
             return;
         }
         if(candidates[index]<=target)
         {            
             a.push_back(candidates[index]);
             r(candidates,target-candidates[index],ans,a,index+1,k);
             a.pop_back();
          }
          r(candidates,target,ans,a,index+1,k);
     }
public:
    vector<vector<int>> combinationSum3(int k, int target) {
        vector<int> a;
        vector<vector<int>>ans;
        vector<int> candidates={1,2,3,4,5,6,7,8,9};
         r(candidates,target,ans,a,0,k);
        return ans;
    }
};