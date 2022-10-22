class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> distance(n,vector<int>(n,1e9));
        for(auto it:edges)
        {
            int from=it[0];
            int to=it[1];
            int cost=it[2];
            distance[from][to]=cost;
            distance[to][from]=cost;
        }
        
        
        for(int via=0;via<n;via++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(i==j)
                    {
                        distance[i][j]=0;
                    }
                    else if(distance[i][j] > distance[i][via]+distance[via][j])
                    {
                        distance[i][j]=distance[i][via]+distance[via][j];
                    }
                }
            }
        }
        int mini=INT_MAX;
        vector<int> count(n,0);
        for(int i=0;i<n;i++)
        {
            int tempcount=0;
            for(int j=0;j<n;j++)
            {
                if(distance[i][j]<=distanceThreshold and i!=j)
                {
                    tempcount++;
                }
            }
            count[i]=tempcount;
            mini=min(mini,tempcount);
        }
        for(int i=n-1;i>=0;i--)
        {
            if(count[i]==mini)
                return i;
        }
        return 0;
        
    }
};