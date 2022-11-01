class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool> visited(n,false);
        queue<int> q;
        q.push(0);
        for(int i=0;i<rooms[0].size();i++)
        {
            q.push(rooms[0][i]);
        }
        while(!q.empty())
        {
            auto ele=q.front();
            q.pop();
            visited[ele]=true;
            for(auto it:rooms[ele])
            {
                if(!visited[it])
                q.push(it);
            }
        }
        for(int i=0;i<visited.size();i++)
        {
            if(visited[i]==false)
            {
                return false;
            }
        }
        return true;
    }
};