class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;
        vector<pair<long long,long long>> adj[n];
        vector<long long> ways(n,0),distance(n,LONG_MAX);
        for(auto it:roads)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        ways[0]=1;
        distance[0]=0;
        long long mod=(long long)(1e9+7);
        pq.push({0,0});
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            long long v=it.second;
            long long w=it.first;
            for(auto i:adj[v])
            {
                long long tempv=i.first;
                long long tempw=i.second;
                if(tempw+w<distance[tempv])
                {
                    distance[tempv]=(tempw+w);
                    pq.push({distance[tempv],tempv});
                    ways[tempv]=ways[v];
                }
                else if(tempw+w==distance[tempv])
                {
                    ways[tempv]=(ways[v]+ways[tempv])%mod;
                }
                
            }
        }
        return ways[n-1]%mod;
        
        
    }
};