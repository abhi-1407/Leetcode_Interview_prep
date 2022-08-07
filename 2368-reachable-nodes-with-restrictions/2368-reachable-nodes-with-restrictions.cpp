class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        unordered_map<int,int> res;
        for(int i=0;i<restricted.size();i++)
            res[restricted[i]]++;
        unordered_map<int,vector<int>> mpp;
        for(int i=0;i<edges.size();i++)
        {
            mpp[edges[i][0]].push_back(edges[i][1]);
            mpp[edges[i][1]].push_back(edges[i][0]);
            
                        
        }
        
        
        if(res.count(0))return 0;//check if zero is restricted
        queue<int>q;//queue for bfs
        vector<int>vis(n,0);//visted array to keep a track of visited one
        
        q.push(0);//push the starting node
        vis[0]=1;//mark visited as 1  
        int count=0;//initialise counter as 0
        while(!q.empty())
        {
            int ele=q.front();
            q.pop();//pop the first element from the queue
            if(res.count(ele))continue;//if this element is restricted then continue
            count++;//else increment the counter
            for(auto it:mpp[ele])//check for the neighbours
            {
                if(vis[it]==0)//if the neighbour is not visited
                {
                   vis[it]=1;//mark it as 1
                   q.push(it);//push it into the queue
                }
            }
        }
        return count;//return the count
    }
};