class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m=matrix.size(),n=matrix[0].size();
        int l=0,r=n-1,t=0,b=m-1;
        int dir=0;
        while(l<=r && t<=b)
        {
            if(dir==0)
            {
                for(int i=l;i<=r;i++)
                {
                    ans.push_back(matrix[t][i]);
                }
                t++;
            }
            else if(dir==1)
            {
                for(int i=t;i<=b;i++)
                {
                    ans.push_back(matrix[i][r]);
                }
                r--;
            }
            else if(dir==2)
            {
                for(int i=r;i>=l;i--)
                {
                    ans.push_back(matrix[b][i]);
                }
                b--;
            }
            else if(dir==3)
            {
                for(int i=b;i>=t;i--)
                {
                    ans.push_back(matrix[i][l]);
                }
                l++;
            }
            dir=(dir+1)%4;
        }
        return ans;
    }
};