class Solution {
public:
    int m[1001][1001] = {};
int minHeightShelves(vector<vector<int>>& b, int max_w, int i = 0, int w = 0, int h = 0) {
    if (i >= b.size()) 
        return h;
    if (m[i][w] == 0) {
        m[i][w] = h + minHeightShelves(b, max_w, i + 1, b[i][0], b[i][1]);
        if (w + b[i][0] <= max_w)
            m[i][w] = min(m[i][w], minHeightShelves(b, max_w, i + 1, w + b[i][0], max(h, b[i][1])));
    }
    return m[i][w];
}
};
