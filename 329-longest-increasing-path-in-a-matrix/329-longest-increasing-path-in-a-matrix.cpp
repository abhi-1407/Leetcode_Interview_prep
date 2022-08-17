class Solution {
    bool isValid(vector<vector<int>>& matrix,int i,int j)//to check if that position is valid
    {
        if(i<0 || j<0 || i>matrix.size()-1 || j>matrix[0].size()-1)
            return false;
        return true;
    }
    int helper(int i,int j,vector<vector<int>>& matrix,vector<vector<int>> &dp)
    {
        if(dp[i][j]!=-1)//if that state is previously visited then use the already stored value
            return dp[i][j];
        int left=0,right=0,up=0,down=0;
        if(isValid(matrix,i+1,j) && matrix[i+1][j]> matrix[i][j] )
        {
             down=helper(i+1,j,matrix,dp);
        }
        if(isValid(matrix,i,j-1) &&matrix[i][j-1]> matrix[i][j] )
        {
             left=helper(i,j-1,matrix,dp);           
        }
        if(isValid(matrix,i-1,j) &&matrix[i-1][j]> matrix[i][j] )
        {
             up=helper(i-1,j,matrix,dp);
            
        }
        if(isValid(matrix,i,j+1) &&matrix[i][j+1]> matrix[i][j] )
        {
             right=helper(i,j+1,matrix,dp);              
        }
        return dp[i][j]=1+max(max(left,right),max(up,down));  //return 1 to max to all the calls
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int maxi=0;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                maxi=max(maxi,helper(i,j,matrix,dp));//calculating max increasing path by taking different starting points
            }
        }
        return maxi;
    }
};