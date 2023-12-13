class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        vector<int> rsum(m,0),csum(n,0);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                rsum[i]+=mat[i][j];
                csum[j]+=mat[i][j];
            }
        }
        bool flag=false;
        int count=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(rsum[i]==1 && csum[j]==1 and mat[i][j]==1)
                    count++;
            }
        }
    
        return count;
    }
};