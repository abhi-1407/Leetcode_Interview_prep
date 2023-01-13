class Solution {
    int dfs(vector<vector<int>> &graphs,string &s,int &res,int index)
    {
        int var1=0,var2=0;
        for(auto it:graphs[index])
        {
            int curr=dfs(graphs,s,res,it);
            if(s[index]==s[it])
                continue;
            if(curr>var2)
                var2=curr;
            if(var2>var1)
                swap(var1,var2);
        }
        res=max(var1+var2+1,res);
        return var1+1;
    }
public:
    int longestPath(vector<int>& parent, string s) {
        int n=parent.size(),res=0;
        vector<vector<int>> graphs(n);
        for(int i=1;i<parent.size();i++)
        {
            graphs[parent[i]].push_back(i);
        }
        dfs(graphs,s,res,0);
        return res;
    }
};