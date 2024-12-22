class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        vector<pair<int, pair<int, int>>> q;
        vector<int> ans(queries.size(), -1);
        
        for (int i = 0; i < queries.size(); i++) {
            q.push_back({max(queries[i][1],queries[i][0]), {min(queries[i][1],queries[i][0]), i}});
        }
        
        sort(q.rbegin(), q.rend());
        
        map<int, int> m; 
        stack<int>s;
        for (int j = 0; j < q.size(); j++) {
            int f = q[j].first;
            int l = heights.size();
            if (j > 0) l = q[j - 1].first;
            
            for (int i = l-1; i >= f; i--) {
                if(s.empty()){
                    s.push(heights[i]);
                    m[heights[i]]=i;
                }
                else{
                    while(!s.empty() && s.top()<=heights[i]){
                        m.erase(s.top());
                        s.pop();
                    }
                    s.push(heights[i]);
                    m[heights[i]]=i;
                }
            }
            int maxi = max(heights[q[j].first], heights[q[j].second.first]);
            if(heights[q[j].second.first]>=heights[q[j].first] && q[j].first!=q[j].second.first){
                auto it = m.upper_bound(maxi);
                if (it != m.end()) {
                   ans[q[j].second.second] = it->second;
                }
            }
            else{
                auto it = m.lower_bound(maxi);
                if (it != m.end()) {
                   ans[q[j].second.second] = it->second;
                }
            }
        }
        
        return ans;
    }
};

