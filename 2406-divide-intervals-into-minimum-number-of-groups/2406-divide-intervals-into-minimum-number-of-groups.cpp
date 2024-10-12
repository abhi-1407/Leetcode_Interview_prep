class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int>arrival;
        vector<int>depart;
        int n = intervals.size();
        for(int i = 0; i < n; i++){
            int a = intervals[i][0];
            int b = intervals[i][1];

            arrival.push_back(a);
            depart.push_back(b);

        }

        sort(arrival.begin() , arrival.end());
        sort(depart.begin() , depart.end());

       int count = 1 , ans = 1;
       int i = 1, j = 0;

       while( i < n && j < n){
            if(arrival[i] <= depart[j]){
                count++;
                i++;
            }
            else{
                count--;
                j++;
            }
            ans = max(ans , count);
       }
        return ans;
    }
};
