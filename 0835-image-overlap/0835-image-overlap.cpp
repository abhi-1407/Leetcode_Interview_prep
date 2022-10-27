class Solution {   
    int count(vector<vector<int>>& img1,vector<vector<int>>& img2,int rowoff,int coloff)
    {
        int n=img1.size(),c=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if((i+rowoff>=n) || (j+coloff>=n) ||(i+rowoff<0)||(j+coloff<0))
                    continue;
                else if(img1[i][j]+img2[i+rowoff][j+coloff]==2)
                    c++;
            }
        }
        return c;
    }
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int maxi=0,n=img1.size();
        for(int i=-n+1;i<n;i++)
        {
            for(int j=-n+1;j<n;j++)
            {
                maxi=max(maxi,count(img1,img2,i,j));
            }
        }
        return maxi;
    }
};