class Solution {
public:
        //simple dfs
    bool dfs(int i,int j,vector<vector<int>> &v){
        int n = v.size();
        int m = v[0].size();
        if(i<0 ||j<0||i>=n||j>=m||v[i][j]==-1||v[i][j]==1e6)
        return false;
        if(i==n-1)return true;

        v[i][j]=1e6; //for visited
        return dfs(i+1,j,v)||dfs(i-1,j,v)||dfs(i,j+1,v)||dfs(i,j-1,v);
        
    }
    //apply dfs on each cell of first row
    bool ispossible(vector<vector<int>>& v){

        for(int i=0;i<v[0].size();i++){
            
            if(v[0][i]==0 && dfs(0,i,v))return true;
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        
        int start = 0;
        int end = cells.size()-1;
        int res = 0;
        while(start<=end){
            int mid = end - (end-start)/2;
            
            vector<vector<int>> v(row,vector<int>(col,0));
            
            //fill water in every cell till mid
            for(int i=0;i<=mid;i++)
            v[cells[i][0]-1][cells[i][1]-1]=-1; //filled with water -1

            //if it is possible to reach last row means it is our possible answer, store it and check for others
            if(ispossible(v)){
                res = mid;
            start = mid+1;
            }
            else
            end = mid-1;
            
        }
        return res+1;
        
    }
};