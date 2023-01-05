class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int start=intervals[0][0],end=intervals[0][1];
        int count=1;
        for(int i=1;i<intervals.size();i++)
        {
               int news=intervals[i][0],newe=intervals[i][1];
               if((start<=news && news<=end) || (start<=newe && newe<=end))
               {
                   start=max(start,news);
                   end=min(end,newe);
               }
               else
               {
                   count++;
                   start=intervals[i][0],end=intervals[i][1];
               }
        }        
        return count;
    }
};