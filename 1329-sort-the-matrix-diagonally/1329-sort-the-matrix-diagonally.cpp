class Solution {
    void SortMat(int i,int j,vector<vector<int>> &mat)
    {
          vector<int> temp;
          int n=mat.size();
          int m=mat[0].size();
          int tempi=i,tempj=j,ptr=0;
          while(tempi<n and tempj<m)
          {
              temp.push_back(mat[tempi][tempj]);
              tempi++;
              tempj++;
          }
          sort(temp.begin(),temp.end());          
          while(i<n and j<m and ptr<temp.size())
          {
              mat[i][j]=temp[ptr];
              i++;
              j++;
              ptr++;
         }
    }
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        vector<vector<int>> visited;
        for(int i=0;i<mat[0].size();i++)
        {
            SortMat(0,i,mat);                
        }
        for(int i=0;i<mat.size();i++)
        {
            SortMat(i,0,mat);
        }
        
        return mat;
    }
};