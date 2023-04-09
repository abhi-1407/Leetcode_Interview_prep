class Solution {

public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=colors.length();
        vector<vector<int>> e(n);
        vector<int> indegree(n,0);
        for(auto it:edges)
        {
            e[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        queue<int> q;
        for(int i=0;i<indegree.size();i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        int nodes=0,ans=0;
        vector<vector<int>> dp(n,vector<int>(26,0));
        while(!q.empty())
        {
            int t=q.front();
            q.pop();
            nodes++;
            ans=max(ans,++dp[t][colors[t]-'a']);
            for(auto it:e[t])
            {
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
                for(int i=0;i<26;i++)
                    dp[it][i]=max(dp[it][i],dp[t][i]);
            }
        }
        if(nodes!=n)
            return -1;
        
        return ans;
        
  }
};