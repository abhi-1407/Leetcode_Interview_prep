class Solution {
    int binary_search(vector<int> &ans)
    {
        int l=0,h=ans.size()-1;
        int index=1e9;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(ans[mid]<0)
            {
                index=mid;
                h=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        if(index==1e9)
            return 0;
        return ans.size()-index;
    }
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count=0;
        for(int i=0;i<grid.size();i++)
        {
            count+=binary_search(grid[i]);
        }
        return count;
    }
};