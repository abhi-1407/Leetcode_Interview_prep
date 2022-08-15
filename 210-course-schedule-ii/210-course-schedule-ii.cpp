class Solution {
    
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        unordered_map<int,list<int>> mpp;
        int count=0;
        for(int it=0;it<prerequisites.size();it++)
        {
            mpp[prerequisites[it][1]].push_back(prerequisites[it][0]);
        }
        vector<int> inDegree(numCourses);
        queue<int> q;
        for(auto it:mpp)//finding all the indegrees of the indexes
        {
            for(auto i: it.second)
            {
                inDegree[i]++;
            }
        }
        for(int i=0;i<inDegree.size();i++)//push all the zero indegree nodes
        {
            if(inDegree[i]==0)
            {
                q.push(i);
            }
        }
        vector<int> ans;
        /* BFS */
        while(!q.empty())
        {
            int element=q.front();
            q.pop();
            count++;
            ans.push_back(element);
            for(auto it: mpp[element])
            {
                inDegree[it]--;//decrease the indegrees of the adjacent nodes  
                if(inDegree[it]==0)//if the indegree is zero then push it into the queue
                    q.push(it);
            }
        }
        vector<int> emptyVector;
        if(count!=numCourses)
         return emptyVector;
        return ans;
        
    }
};