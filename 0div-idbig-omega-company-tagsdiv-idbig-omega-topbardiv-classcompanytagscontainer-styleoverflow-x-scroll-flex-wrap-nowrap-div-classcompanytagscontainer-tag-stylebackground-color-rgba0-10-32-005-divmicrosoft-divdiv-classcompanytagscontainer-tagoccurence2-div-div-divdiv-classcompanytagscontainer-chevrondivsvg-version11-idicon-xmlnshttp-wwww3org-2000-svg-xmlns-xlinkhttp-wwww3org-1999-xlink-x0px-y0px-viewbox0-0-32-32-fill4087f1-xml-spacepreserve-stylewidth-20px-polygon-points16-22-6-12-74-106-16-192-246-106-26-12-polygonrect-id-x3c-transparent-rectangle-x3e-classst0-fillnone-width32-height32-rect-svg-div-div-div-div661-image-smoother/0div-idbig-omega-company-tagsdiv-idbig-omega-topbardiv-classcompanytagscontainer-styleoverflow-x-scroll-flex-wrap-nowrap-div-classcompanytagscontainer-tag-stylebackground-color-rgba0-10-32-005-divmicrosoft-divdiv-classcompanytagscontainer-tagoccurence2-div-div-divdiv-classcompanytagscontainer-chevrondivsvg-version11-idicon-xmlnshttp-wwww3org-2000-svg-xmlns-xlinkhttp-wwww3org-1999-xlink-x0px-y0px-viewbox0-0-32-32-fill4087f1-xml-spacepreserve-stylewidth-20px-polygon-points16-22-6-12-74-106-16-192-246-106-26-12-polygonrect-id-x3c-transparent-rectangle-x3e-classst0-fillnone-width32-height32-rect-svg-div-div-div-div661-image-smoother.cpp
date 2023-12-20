class Solution {
public:
    int NeighborsAvrage(vector<vector<int>>& img, int i, int j, int n, int m){
        static const int rowOffsets[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
        static const int colOffsets[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

        int c = 0, sum = 0;
        for(int k = 0; k < 8; ++k){
            int newi = i + rowOffsets[k];
            int newj = j + colOffsets[k];
            if(newi >= 0 && newi < n && newj >= 0 && newj < m){
                sum += img[newi][newj];
                ++c;
            }
        }
        ++c;
        sum += img[i][j];
        return floor(sum/c);
    }

    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size();
        int m = img[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++){
                ans[i][j] = NeighborsAvrage(img, i, j, n,m);
            }
        }
        return ans;
    }
};