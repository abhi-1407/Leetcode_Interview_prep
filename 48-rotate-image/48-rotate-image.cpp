class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //simple trick is to take transpose and then reverse each row
        //only transpose the elements of upper triangle as if we take transpose of the whole thing we will get the original matrix
        for(int i=0;i<matrix.size();i++) 
        {
            for(int j=i;j<matrix[i].size();j++)
            {
                int temp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            }
        }
        //reverse each row
        for(int i=0;i<matrix.size();i++)
        {
            int l=0;
            int r=matrix[i].size()-1;
            while(l<r)
            {
                int temp=matrix[i][l];
                matrix[i][l]=matrix[i][r];
                matrix[i][r]=temp;
                l++;
                r--;
            }
        }
        
    }
};