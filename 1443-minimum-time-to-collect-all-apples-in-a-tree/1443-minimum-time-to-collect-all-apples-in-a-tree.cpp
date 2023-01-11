class Solution {
    bool dfs(int idx , unordered_map<int , vector<int>>&mp , vector<bool>&hasApple , int &count , vector<bool>&visited)
    {
        visited[idx] = true ; 
        bool what = false ; 
        for(auto i : mp[idx])
        {
            if(visited[i]) continue ; 
            bool ans = dfs(i , mp , hasApple , count , visited) ; 
            if(ans) count+= 2 ; 
            what = what || ans ; 
        }
        what = what || hasApple[idx] ; 
        return what ; 
    }
    public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int , vector<int>> mp ; 
        for(auto i : edges)
        {
            mp[i[0]].push_back(i[1]) ; 
            mp[i[1]].push_back(i[0]) ; 
        }
        int count = 0 ; 
        
        vector<bool>visited(n , false) ; 
        visited[0] = true ; 
        for(int i = 0 ; i < mp[0].size() ; i++)
        {
            if(visited[mp[0][i]]) continue ; 
            bool ans = dfs(mp[0][i] , mp , hasApple , count , visited) ; 
            if(ans) count += 2 ; 
        }
        return count ; 
    }
};