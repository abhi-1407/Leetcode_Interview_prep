class Solution {
public:
    int jobScheduling(vector<int>& a, vector<int>& b, vector<int>& c) {
        int n = a.size(), cur = 0, ret = 0;
        priority_queue <array<int, 2>> q;
        // sort
        vector <int> d(n);
        for (int i = 0; i < n; i++)  d[i] = i;
        sort(d.begin(), d.end(), [&](const auto &x, const auto &y) {
            return a[x] < a[y]; 
        });
        // heap + dp!
        for (int i = 0; i < n; i++) {
            int j = d[i];
            while (!q.empty() && -q.top()[0] <= a[j]) {
                cur = max(cur, q.top()[1]);
                q.pop();
            }
            q.push({-b[j], cur + c[j]});
            ret = max(ret, cur + c[j]);
        }
        return ret;
    }
};