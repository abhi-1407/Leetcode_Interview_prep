class Solution {
public: 
    int k;
    long long ans=0;
    long long dfs(vector<int>adj[],int node,int par){
        long long count=1; //Count==>Total nodes in subtree with node as parent
        for(int child:adj[node]){
            if(child!=par){
               count+=dfs(adj,child,node);
            }
        }
        ans+=ceil((double)count/k);  // Grouping people in same cars before returning to parent node
        return count;
       
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n=roads.size()+1;
        vector<int>adj[n];
        for(auto &i:roads){
            adj[i[0]].push_back(i[1]);
             adj[i[1]].push_back(i[0]);
        }
        k=seats;
        long long ans1=0;
       for(auto i:adj[0]){
           long long a=dfs(adj,i,0);
           ans1+=ans;
           ans=0;
       }
        return ans1;
        
        
    }
};