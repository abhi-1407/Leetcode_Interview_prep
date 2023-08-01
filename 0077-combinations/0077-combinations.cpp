class Solution {
    void helper(vector<int> &temp,vector<vector<int>> &ans,int index,int k,vector<int> &vec)
    {
        if(index==vec.size())
        {
            if(k==0)
            {
                ans.push_back(temp);

            }
            return;
        }
        temp.push_back(vec[index]);
        helper(temp,ans,index+1,k-1,vec);
        temp.pop_back();
        helper(temp,ans,index+1,k,vec);
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> vec;
        for(int i=1;i<=n;i++)
                vec.push_back(i);
        vector<vector<int>> ans;
        vector<int> temp;
        helper(temp,ans,0,k,vec);
        return ans;
    }
};