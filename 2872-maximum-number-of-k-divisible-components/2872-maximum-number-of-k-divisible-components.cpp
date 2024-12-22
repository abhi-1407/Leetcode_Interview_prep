class Solution {
    long long helper(vector<int> adj[],int &count,int ele,vector<int> &values,int k,int par){
        long long sum = values[ele];
        for(auto it:adj[ele]){
            if(par==it) continue;
            sum += helper(adj,count,it,values,k,ele);
        }
        sum %=k;
        if(sum == 0){
            count++;
        }
        return sum;
    }
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<int> adj[n];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int count = 0;
        helper(adj,count,0,values,k,-1);
        return count;
    }
};