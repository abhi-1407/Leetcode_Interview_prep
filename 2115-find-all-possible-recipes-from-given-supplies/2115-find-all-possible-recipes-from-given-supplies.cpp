class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string,int> indegree;
        vector<string>  ans;
        unordered_map<string,vector<string>> adj;
        for(int i=0;i<recipes.size();i++)
        {
            for(auto it:ingredients[i])
            {
                adj[it].push_back(recipes[i]);
                indegree[recipes[i]]++;
            }
        }
        queue<string> q;
        for(auto it:indegree)
        {
            if(it.second==0)
            q.push(it.first);
        }
        for(auto it:supplies)
            q.push(it);
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            for(auto i:adj[it])
            {
                
                indegree[i]--;
                if(indegree[i]==0)
                {
                    q.push(i);
                    ans.push_back(i);
                }
            }
        }
        return ans;
    }
};