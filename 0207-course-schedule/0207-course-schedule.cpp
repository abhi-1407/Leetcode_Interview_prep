class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int> indegree(numCourses,0);
        for(auto it:prerequisites)
        {
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        queue<int> q;
        for(int i=0;i<indegree.size();i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            for(auto i:adj[it])
            {
                --indegree[i];
                if(indegree[i]==0)
                {
                    q.push(i);
                }
            }
        }
        for(auto it:indegree)
        {
            if(it!=0)
                return false;
        }
        return true;
        
    }
};

