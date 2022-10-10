class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
       intervals.push_back(newInterval);
       sort(intervals.begin(),intervals.end());
       auto temp=intervals[0];
       vector<vector<int>> ans;
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