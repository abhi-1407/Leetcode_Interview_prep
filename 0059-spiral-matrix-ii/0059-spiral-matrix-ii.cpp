class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n,vector<int> (n,0));
        int l=0,r=n-1,t=0,b=n-1;
        int count=1;
        int dir=0;
        while(l<=r && t<=b)
        {
            if(dir==0)
            {
                for(int i=l;i<=r;i++)
                {
                    matrix[t][i]=count;
                    count++;
                }
                t++;
            }
            else if(dir==1)
            {
                for(int i=t;i<=b;i++)
                {
                    matrix[i][r]=count;
                    count++;
                }
                r--;
            }
            else if(dir==2)
            {
                for(int i=r;i>=l;i--)
                {
                    matrix[b][i]=count;
                    count++;
                }
                b--;
            }
            else if(dir==3)
            {
                for(int i=b;i>=t;i--)
                {
                    matrix[i][l]=count;
                    count++;
                }
                l++;
            }
            
            dir=(dir+1)%4;
        }
        return matrix;
    }
};

        