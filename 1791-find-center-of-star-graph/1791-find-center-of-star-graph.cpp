class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int x=edges[0][0];
        int y=edges[0][1];
        int n=edges.size();
        int ans=-1;
        
        for(int i=1;i<n;i++)
        {
            x=(x==edges[i][0]) ? x : edges[i][1];
        }
        return x;
    }
};