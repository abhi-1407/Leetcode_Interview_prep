class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size(),maxi=INT_MIN;
        for(int i=0;i<m-2;i++)
        {
            for(int j=0;j<n-2;j++)
            {
                int e1=grid[0+i][0+j],e2=grid[0+i][1+j],e3=grid[0+i][2+j],e4=grid[2+i][0+j],e5=grid[2+i][1+j],e6=grid[2+i][2+j],e7=grid[1+i][1+j];
                int sum=e1+e2+e3+e4+e5+e6+e7;
                maxi=max(maxi,sum);
            }
        }
        return maxi;
    }
};