class Solution {
    bool check(int i,int j,vector<vector<int>>& matrix)
    {
        int ele=matrix[i][j];
        int n=matrix.size(),m=matrix[0].size();
        while(i<n && j<m && i>=0 && j>=0)
        {
            if(ele!=matrix[i][j])
                return false;
            i++;
            j++;
        }
        return true;
    }
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++)
        {
            if(!check(i,0,matrix))
                return false;
        }
        for(int i=0;i<matrix[0].size();i++)
        {
            if(!check(0,i,matrix))
                return false;
        }
        return true;
    }
};