class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> mpp;
        vector<int> one,two;
        for(auto it:matches)
        {
            int win=it[0];
            int lose=it[1];
            if(mpp.count(win)==0)
            {
               mpp[win]=0; 
            }
            mpp[lose]++;
        
        }
        
        for(auto it:mpp)
        {
            if(it.second==0)
                one.push_back(it.first);
            else if(it.second==1)
                two.push_back(it.first);
        }
        return {one,two};
    }
};