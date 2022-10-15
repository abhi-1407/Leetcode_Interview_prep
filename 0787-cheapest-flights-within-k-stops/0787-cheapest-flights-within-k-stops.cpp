class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto it:flights)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,pair<int,int>>> q;
        vector<int> prices(n,1e9);
        prices[src]=0;
        q.push({0,{src,0}});
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            
            int stops=it.first;
            int source=it.second.first;
            int price=it.second.second;
            if(stops > k)
                continue;
            for(auto it:adj[source])
            {
                int adjnode=it.first;
                int adjprice=it.second;
                if(stops<=k && price + adjprice < prices[adjnode])
                {
                    prices[adjnode]=price+adjprice;
                    q.push({stops+1,{adjnode,price+adjprice}});
                }
            }
        }
        if(prices[dst]==1e9)
            return -1;
        else
            return prices[dst];
        
    }
};