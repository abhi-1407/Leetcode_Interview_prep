class Solution {
private:
    bool checkValid(int i,int j,int m,int n)
    {
        if(i<0 || j<0 || j>n-1 || i> m-1)return false;
        return true;
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>>ans(mat.size(),vector<int>(mat[0].size(),-1));
        queue<pair<int,int>>q;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({i,j});
                    ans[i][j]=0;
                }
                
            }
        }
        int m=mat.size();
        int n=mat[0].size();
        while(!q.empty())
        {
             int i=q.front().first;
             int j=q.front().second;
             q.pop();
             if(checkValid(i+1,j,m,n)&& ans[i+1][j]==-1)
             {
                 ans[i+1][j]=ans[i][j]+1;
                 q.push({i+1,j});
             }
             if(checkValid(i,j+1,m,n)&& ans[i][j+1]==-1)
             {
                 ans[i][j+1]=ans[i][j]+1;
                 q.push({i,j+1});
             }
             if(checkValid(i-1,j,m,n)&& ans[i-1][j]==-1)
             {
                 ans[i-1][j]=ans[i][j]+1;
                 q.push({i-1,j});
             }
             if(checkValid(i,j-1,m,n)&& ans[i][j-1]==-1)
             {
                 ans[i][j-1]=1+ans[i][j];
                 q.push({i,j-1});
             }
            
        }     
        return ans;
    }
    
};