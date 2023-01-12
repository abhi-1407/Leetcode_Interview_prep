class Solution {    
    vector<int> dfs(int node,string &labels,vector<vector<int>> &graphs,vector<bool> &visited,vector<int> &ans)
    {
        visited[node]=true;
        vector<int> count(26,0);
        for(auto it:graphs[node])
        {
            if(!visited[it])
            {
                vector<int> adjcount(26,0);
                adjcount=dfs(it,labels,graphs,visited,ans);
                for(int i=0;i<26;i++)
                {
                    count[i]+=adjcount[i];//add the count of the unvisited subtrees into the current node's freq arr
                }
            }
        }
        char ch=labels[node];//extract the char corresponding to this node
        count[ch-'a']++;//increment the freq of the current character
        ans[node]=count[ch-'a'];//count of current char 
        return count;//return the freq of elements in the subtree
    }
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> graph(n);
        for(auto it:edges)
        {
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        vector<bool> visited(n,false);
        vector<int> ans(n,0);
        dfs(0,labels,graph,visited,ans); 
        return ans;
    }
};