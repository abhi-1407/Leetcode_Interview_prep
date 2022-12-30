class Solution {
    void dfs(vector<vector<int>>& graph,int node,vector<int> &visited,vector<vector<int>> &ans,vector<int> &temp)
    {
        if(node==graph.size()-1)
        {
            temp.push_back(node);
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        visited[node]=1;
        temp.push_back(node);
        
        for(auto it:graph[node])
        {
            if(visited[it]==-1)
            {
                dfs(graph,it,visited,ans,temp);
            }
        }
        visited[node]=-1;
        temp.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> visited(n,-1);
        vector<vector<int>> ans;
        vector<int> temp;
        dfs(graph,0,visited,ans,temp);
        return ans;
        
    }
};