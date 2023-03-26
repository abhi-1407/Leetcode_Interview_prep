class Solution {
public:
	// Node stores the index which we have already seen in the cycle
    int cycle = 0, ans = INT_MIN, node;
	
    bool DFS(int i, vector<bool> &visited, vector<bool> &currVisited, vector<vector<int>> &graph){
        visited[i] = true;
        currVisited[i] = true;
		
		// Traversing through the adjacent vertices
        for(auto adj: graph[i]){
			// Not visited
            if(!visited[adj]){
				// Cycle found in its adjacent vertices
                if(DFS(adj, visited, currVisited, graph) && node != i){
                    cycle++;
					currVisited[i] = false;
                    return true;
                }
				// Last node in the cycle
                else{
					currVisited[i] = false;
                    return false;
                }
            }
            // Cycle found
            else if(visited[adj] && currVisited[adj]){
                cycle++;
                node = adj;
				currVisited[i] = false;
                return true;
            }
        }
        currVisited[i] = false;
        return false;
    }
    
    int longestCycle(vector<int>& edges) {
		// Create adjacency list from the given edges
        vector<vector<int>> graph(edges.size());
        for(int i=0; i<edges.size(); i++){
            if(edges[i] == -1){
                continue;
            }
            graph[i].push_back(edges[i]);
        }
        
        vector<bool> visited(edges.size(), false);
        vector<bool> currVisited(edges.size(), false);
        
        for(int i=0; i<edges.size(); i++){
            if(!visited[i]){
                DFS(i, visited, currVisited, graph);
				// Cycle found
                if(cycle != 0){
                    ans = max(ans, cycle+1);
                    cycle = 0;
                }
            }
        }
        
        return ans == INT_MIN ? -1 : ans;
    }
};
