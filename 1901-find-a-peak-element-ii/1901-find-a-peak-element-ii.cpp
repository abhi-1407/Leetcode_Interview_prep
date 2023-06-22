class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int top=0,bottom=n-1;
        while(top<=bottom)
        {
            int mid_row=top+(bottom-top)/2;
            int col=max_element(mat[mid_row].begin(),mat[mid_row].end())-mat[mid_row].begin();
            if(mid_row-1>=0 && mat[mid_row-1][col]>mat[mid_row][col])
            {
                bottom=mid_row-1;
            }
            else if(mid_row+1<n && mat[mid_row+1][col]>mat[mid_row][col])
            {
                top=mid_row+1;
            }
            else // peak found
            {
                return {mid_row,col};
            }
        }
        return {-1,-1};
    }
};