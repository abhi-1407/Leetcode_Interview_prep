class Solution {
    bool detectCycle(int n,unordered_map<int,list<int>>mpp)//checking if there's a cycle using kahn's algorithm
    {
        vector<int> indegree(n);
        queue<int> q;
        for(auto it:mpp)//finding all the indegrees
        {
            for(auto i:it.second)
            {
                indegree[i]++;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)//pushing all the nodes with zero indegree
                q.push(i);
        }
        int count=0;//initialising count as 0
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            count++;
            for(auto i:mpp[it])
            {
                indegree[i]--;//decrease the indegree of the adjacent nodes
                if(indegree[i]==0)
                    q.push(i);
            }
        }
        return count==n;//check if the number of nodes are same as count, which is false in case of a cycle
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        unordered_map<int,list<int>>mpp;
        for(int i=0;i<pre.size();i++)
        {
            int a=pre[i][0];
            int b=pre[i][1];
            mpp[a].push_back(b);
        }
        return detectCycle(numCourses,mpp);
    }
};