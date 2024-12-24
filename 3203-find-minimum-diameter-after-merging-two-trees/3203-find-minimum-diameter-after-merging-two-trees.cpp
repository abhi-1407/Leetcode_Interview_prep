class Solution {
public:
    pair<int, int> minDiameter(vector<vector<int>>& edges) {
        vector<vector<int>> graph(edges.size() + 1); 
        for (vector<int>& edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<int> degrees(edges.size() + 1);
        for (int i = 0; i < graph.size(); i++) {
            degrees[i] = graph[i].size();
        }

        queue<int> q;

        for (int i = 0; i < degrees.size(); i++) {
            if (degrees[i] == 1) {
                q.push(i);
            }
        }

        int deletions = 0;
        int nodeCount = edges.size()+1;

        int dist1 = 0;
        int dist2 = 0;
        while (!q.empty() && nodeCount > 2) {
            int curSize = q.size();

            for (int i = 0; i < curSize; i++) {
                int curLeaf = q.front();
                q.pop();
                nodeCount--;
                for (int neighbour: graph[curLeaf]) {
                    degrees[neighbour]--;
                    if (degrees[neighbour] == 1) {
                        q.push(neighbour);
                    }
                    if (deletions+1 > dist1) dist1 = deletions+1;
                    else if (deletions+1 > dist2) dist2 = deletions+1;

                }
            }

            deletions++;
        }

        if (nodeCount == 2)
            return {deletions+1, dist1+dist2+1};
        
        return {deletions, dist1+dist2};
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        pair<int, int> values1 = minDiameter(edges1);
        pair<int, int> values2 = minDiameter(edges2);
        return max({values1.first + values2.first + 1, values1.second, values2.second});
    }
};