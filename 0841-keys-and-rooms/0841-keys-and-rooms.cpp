class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int> visited(n,false);
        visited[0]=true;
        queue<int> q;
        q.push(0);
        while(!q.empty())
        {
            int ele=q.front();
            q.pop();
            for(auto it:rooms[ele])
            {
                if(!visited[it])
                {
                    visited[it]=true;
                    q.push(it);                   
                }                
            }
        }
        for(auto it:visited)
        {
            if(!it)
                return false;
        }
        return true;
    }
};