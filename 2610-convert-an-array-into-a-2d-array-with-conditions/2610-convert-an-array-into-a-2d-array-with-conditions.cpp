class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> mpp;
        vector<vector<int>> ans;
        int max_lim=0;
        for(auto it:nums)
        {
            mpp[it]++;
            max_lim=max(max_lim,mpp[it]);
        }
        for(int i=0;i<max_lim;i++)
        {
            vector<int> temp;
            for(auto it:mpp)
            {
                if(it.second>0)
                temp.push_back(it.first);
                mpp[it.first]--;
            } 
            ans.push_back(temp);
        }
        return ans;
        
        
    }
};