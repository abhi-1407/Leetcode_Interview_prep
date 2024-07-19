class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        vector<int> rowMin(rows,INT_MAX);
        vector<int> colMax(cols,INT_MIN);
        
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                rowMin[i]=min(rowMin[i],matrix[i][j]);
                colMax[j]=max(colMax[j],matrix[i][j]);
            }
        }
        vector<int> res;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(rowMin[i]==matrix[i][j] && colMax[j]==matrix[i][j])
                    res.push_back(matrix[i][j]);
            }
        }
        return res;
    }
};