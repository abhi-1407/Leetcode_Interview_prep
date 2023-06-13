class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string,int> mpp1,mpp2;
        for(int i=0;i<grid.size();i++)
        {
            string st;
            for(int j=0;j<grid[0].size();j++)
            {
                st+=to_string(grid[i][j])+"#";
            }
            mpp1[st]++;
        }
        
        for(int i=0;i<grid[0].size();i++)
        {
            string st;
            for(int j=0;j<grid.size();j++)
            {
                st+=to_string(grid[j][i])+"#";
            }
            mpp2[st]++;
        }
        int count=0;
        for(auto it:mpp2)
        {
            if(mpp1.find(it.first)!=mpp1.end())
            {
                count+=it.second*mpp1[it.first];
            }
        }
        return count;
    }
};