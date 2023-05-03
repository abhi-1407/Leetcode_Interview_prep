class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int l=0,r=n-1;
        while(l<=r)
        {
            int midRow=l+(r-l)/2;
            int midCol=max_element(mat[midRow].begin(),mat[midRow].end())-mat[midRow].begin();
            if(midRow < n-1 && mat[midRow][midCol]<mat[midRow+1][midCol])
                l=midRow+1;
            else if(midRow > 0 && mat[midRow][midCol]<mat[midRow-1][midCol])
                r=midRow-1;
            else
                return {midRow,midCol};
        }
        return {-1,-1};
       
    }
};