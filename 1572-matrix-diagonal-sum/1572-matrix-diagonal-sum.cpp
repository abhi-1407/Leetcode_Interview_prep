class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        int sum=0;
        // int i=0,j=m-1,k=0,sum=0;
        // while(i<m && j>=0 && k<n)
        // {
        //     if(i==j)
        //     {
        //         sum+=mat[i][k];
        //     }
        //     else
        //     {
        //         sum+=mat[i][k];
        //         sum+=mat[j][k];
        //     }
        //     i++;
        //     j--;
        //     k++;
        // }
        for(int i=0;i<mat.size();i++)
        {
            sum+=mat[i][i];
            if(i!=n-i-1)
                sum+=mat[i][n-i-1];
        }
        return sum;
    }
};