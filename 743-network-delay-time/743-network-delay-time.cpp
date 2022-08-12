class Solution {
    int MinTime(unordered_map<int,list<pair<int,int>>> graph,int n,int k)
    {
        vector<int> distances(n+1,INT_MAX);
        set<pair<int,int>> s;
        s.insert({k,0});//insert the first node
        distances[k]=0;//mark its time as 0
        while(!s.empty())
        {
            auto i=*(s.begin());//pull out the first node
            int node=i.first;
            int distance=i.second;
            s.erase(s.begin());//remove this from the set
            for(auto it: graph[node])//iterate over its neighbours
            {
                int d=it.second;//find the time associated with it
                if( d+distance < distances[it.first])//if its less than the current value
                {
                    if(s.find({it.first,it.second})!=s.end())//see if there's an exisiting entry 
                    {
                        s.erase({it.first,it.second});//remove it
                        s.insert({it.first,d+distance});//replace it with the new entry
                    }
                    else
                    {
                        s.insert({it.first,d+distance});//else insert a new entry
                    }
                    distances[it.first]=d+distance;//update the distance array
                }
                
            }
                        
        }
        int maxi=INT_MIN;
        for(int i=1;i<distances.size();i++)
            maxi=max(distances[i],maxi);
        /* if any node as time as INT_MAX then its not possible to transmit signal to that node */
        if(maxi==INT_MAX)
            return -1;//return -1 in that case
        else
            return maxi;//return maximum time as that would be min value to transmit to all the nodes
    }
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,list<pair<int,int>>> graph;
        for(auto it: times)
        {
            int u=it[0];
            int v=it[1];
            int time=it[2];
            graph[u].push_back({v,time});  //put the entries in the map          
        }
        return MinTime(graph,n,k);
        
    }
};