class Solution {
//     bool checkV(int i , int j,int m,int n)
// {
//     if(i<0 || j<0 || i> m-1 || j> n-1)
//         return false;
//     return true;
// }

    void helper(int i,int j,vector<vector<int>> &image,int color,int col)
    {
        if(i<0 || j<0 || i>=image.size() || j>=image[0].size() || image[i][j]!=col)
            return ;
        image[i][j]=color;
        helper(i-1,j,image,color,col);
        helper(i+1,j,image,color,col);
        helper(i,j-1,image,color,col);
        helper(i,j+1,image,color,col);
    }


public:

     vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color){
         int col=image[sr][sc];
         if(image[sr][sc]!=color)//else you'll get a runtime error
         helper(sr,sc,image,color,col);
         return image;
//    }
//     vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
//         queue<pair<int,int>> pq;
//         pq.push({sr,sc});
//         int m=image.size();
//         int n=image[0].size();
//         if(image[sr][sc]==color)
//             return image;
//         int c=image[sr][sc];
//         vector<vector<int>> ans( m,vector<int>(n,-1));
//         for(int i=0;i<m;i++)
//         {
//             for(int j=0;j<n;j++)
//             {
//                 if(image[i][j]!=c)
//                     ans[i][j]=image[i][j];
//             }
//         }
//         ans[sr][sc]=color;
//         while(!pq.empty())
//         {
            
//             int i=pq.front().first;            
//             int j=pq.front().second;
//             pq.pop();
            

//             if(checkV(i+1,j,m,n) && ans[i+1][j]==-1 && image[i+1][j]==c)
//             {
//                 ans[i+1][j]=color;
//                 pq.push({i+1,j});
//             }
//             if(checkV(i,j+1,m,n) && ans[i][j+1]==-1 && image[i][j+1]==c )
//             {
//                 ans[i][j+1]=color;
//                 pq.push({i,j+1});
                
//             }
//             if(checkV(i-1,j,m,n) && ans[i-1][j]==-1 && image[i-1][j]==c)
//             {
//                 ans[i-1][j]=color;
//                 pq.push({i-1,j});
//             }
//             if(checkV(i,j-1,m,n) && ans[i][j-1]==-1 && image[i][j-1]==c)
//             {
//                 ans[i][j-1]=color;
//                 pq.push({i,j-1});
//             }
            
//         }
//         for(int i=0;i<m;i++)
//         {
//             for(int j=0;j<n;j++)
//             {
//                 if(ans[i][j]==-1)
//                     ans[i][j]=image[i][j];
//             }
//         }
//         return ans;
    }
};