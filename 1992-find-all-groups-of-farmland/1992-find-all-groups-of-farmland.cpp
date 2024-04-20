class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        int m=land.size();
        int n=land[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(land[i][j]==0)
                    continue;
                else
                {
                    vector<int> temp;
                    int r1=i;
                    int c1=j;
                    int tempi=i;
                    int tempj=j;
                    while(tempi<m)
                    {
                        if(tempi+1<m && land[tempi+1][c1]==1)
                            tempi++;
                        else 
                            break;
                    }
                    while(tempj<n)
                    {
                        if(tempj+1<n && land[r1][tempj+1]==1)
                            tempj++;
                        else 
                            break;
                    }
                    int r2=tempi;
                    int c2=tempj;
                    cout<<r1<<" "<<c1<<" "<<r2<<" "<<c2<<endl;
                    temp.push_back(r1);
                    temp.push_back(c1);
                    temp.push_back(r2);
                    temp.push_back(c2);
                    ans.push_back(temp);
                    for(int k=r1;k<=r2;k++)
                    {
                        for(int l=c1;l<=c2;l++)
                        {
                            land[k][l]=0;
                        }
                    }
                    }
            }
        }
        return ans;
    }
};