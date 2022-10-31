class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
         multiset<int,greater<int>> ms;
         vector<pair<int,int>> heights;
         for(auto it:buildings)
         {
             heights.push_back({it[0],-it[2]});//+ve represents the left edge of the building
             heights.push_back({it[1],+it[2]});//-ve represents the right edge of the building
         }
        sort(heights.begin(),heights.end());//so that we have points in a line(they are in order)
        ms.insert(0);
        vector<vector<int>> ans;
        int OngoingHeight=0;
        for(auto it:heights)
        {
            int currPoint=it.first;
            int currHeight=it.second;
            if(currHeight<0)
            {
                ms.insert(-currHeight);
            
            }
            else
            {
                ms.erase(ms.find(currHeight));
            }
            //if the max height has changed then this should be in our ans            
            int NewMax =*ms.begin();
            if(NewMax!=OngoingHeight)
            {
                OngoingHeight=NewMax;
                ans.push_back({currPoint,OngoingHeight});                
                   
            }
                    
        }
        return ans;
        
    }
};