/* We erase the interval with higher end as it would eat up many intervals */
/* ask the interviwer if 1,2 and 2,3 can be merged or not, here they cant be but in merge intervals they can be */
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int count = 0;
        auto prev = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < prev[1]) {
                count++;
                prev[1] = min(prev[1], intervals[i][1]);//erase interval with higher end val
            } else {
                prev=intervals[i];
            }
        }
        return count;
    }
};

