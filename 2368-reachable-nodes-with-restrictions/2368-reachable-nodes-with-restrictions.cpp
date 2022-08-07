class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        unordered_map<int,int> res;
        for(int i=0;i<restricted.size();i++)
            res[restricted[i]]++;
        unordered_map<int,vector<int>> mpp;
        for(int i=0;i<edges.size();i++)
        {
            int a=edges[i][0];
            int b=edges[i][1];
            if((res.find(a)==res.end()) && (res.find(b)==res.end()))
            {
                mpp[edges[i][0]].push_back(edges[i][1]);
                mpp[edges[i][1]].push_back(edges[i][0]);
            }
                        
        }
        
        
        if(res.count(0))return 0;
        queue<int>q;
        vector<int>vis(n,0);
        
        q.push(0);
        vis[0]=1;        
        int count=0;
        while(!q.empty())
        {
            int ele=q.front();
            q.pop();
            if(res.count(ele))continue;
            count++;
            for(auto it:mpp[ele])
            {
                if(vis[it]==0)
                {
                   vis[it]=1;
                   q.push(it);
                }
            }
        }
        return count;
    }
};