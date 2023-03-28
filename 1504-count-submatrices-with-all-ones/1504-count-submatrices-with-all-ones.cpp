class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        int arr[n][m];
        for(int i=0;i<n;i++)
        {
            int count=0;
            for(int j=m-1;j>=0;j--)
            {
                if(mat[i][j])
                    count++;
                else
                    count=0;
                arr[i][j]=count;
            }
        }
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int x=INT_MAX;
                for(int k=i;k<n;k++)
                {
                    x=min(x,arr[k][j]);
                    ans+=x;
                }
            }
        }
        return ans;
    }
};