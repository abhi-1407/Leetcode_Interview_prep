class Solution {
public:
    int p=0,q=0;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<int>> ata(m,vector<int>(n,0));
        vector<vector<int>> pac(m,vector<int>(n,0));
        
        for(int i=0;i<m;i++)
        {
            dfs(heights,pac,heights[i][0],i,0);
            dfs(heights,ata,heights[i][n-1],i,n-1);
        }
        for(int i=0;i<n;i++)
        {
            dfs(heights,pac,heights[0][i],0,i);
            dfs(heights,ata,heights[m-1][i],m-1,i);
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(ata[i][j] && pac[i][j])
                    res.push_back({i,j});
            }
        }
        return res;
    }
    void dfs(vector<vector<int>>& v,vector<vector<int>>& sea,int val,int i,int j)
    {
        if(i<0 || j<0 || i>=v.size() || j>=v[0].size() || sea[i][j] || v[i][j] < val)
            return;
        
        sea[i][j]=1;
        dfs(v,sea,v[i][j],i-1,j);
        dfs(v,sea,v[i][j],i,j-1);
        dfs(v,sea,v[i][j],i+1,j);
        dfs(v,sea,v[i][j],i,j+1);
    }
};