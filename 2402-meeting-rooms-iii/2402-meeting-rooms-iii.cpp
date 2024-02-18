#define ll long long
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
         priority_queue<ll,vector<ll>,greater<ll>> pq1;   // available
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq2; //busy
        vector<ll> roomCount(n,0);
        sort(meetings.begin(),meetings.end());
        for(int i=0;i<n;i++) pq1.push(i);
        for(auto meet : meetings){
            ll start=meet[0], end=meet[1];
            while(!pq2.empty() and start>=pq2.top().first){
                pq1.push(pq2.top().second);
                pq2.pop();
            }
            if(pq1.size()){
                ll room=pq1.top();
                pq1.pop();
                pq2.push({end,room});
                roomCount[room]++;
                continue;
            }
            ll nextEnd=pq2.top().first;
            ll nextRoom=pq2.top().second;
            pq2.pop();
            pq2.push({nextEnd+(end-start),nextRoom});
            roomCount[nextRoom]++;
        }
    return max_element(roomCount.begin(),roomCount.end())-roomCount.begin(); 
    }
};