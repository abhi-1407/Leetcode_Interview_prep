#define ll long long
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size(),sum=0;
        sort(points.begin(),points.end());
        vector<ll> visited(n,0);
        vector<ll> distance(n,LLONG_MAX);
        priority_queue<vector<ll>,vector<vector<ll>>,greater<vector<ll>>>pq;
        pq.push({0,points[0][0],points[0][1],0});
        //visited[0]=1;
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            ll node=it[3];
            if(visited[node])
                continue;
            visited[node]=true;
            sum+=it[0];
            
            for(ll i=0;i<n;i++)
            {
                ll dist=(abs(points[i][0]-it[1])+abs(points[i][1]-it[2]));
                if(distance[i]<dist)
                    continue;
                pq.push({dist,points[i][0],points[i][1],i});
                distance[i]=dist;
            }
        }
        return sum;
    }
};