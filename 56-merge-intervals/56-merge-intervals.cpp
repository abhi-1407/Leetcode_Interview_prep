class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        auto temp=intervals[0];
        for(int i=1;i<intervals.size();i++)
        {
            auto temp2=intervals[i];
            if(temp[1]>=temp2[0])
            {
                temp[1]=max(temp[1],intervals[i][1]);
            }
            else
            {
                ans.push_back(temp);  
                temp=temp2;                              
            }
        }
        ans.push_back(temp);
        return ans;
    }
};