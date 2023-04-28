class Solution {
    bool similar(string &a,string &b)
    {
        int count=0;
        for(int i=0;i<a.length();i++)
        {
            if(a[i]!=b[i])
                count++;
        }
        return ((count==2) || (count==0));
    }
    
    void dfs(int index,vector<string> &strs,vector<bool> &visited)
    {
        visited[index]=true;
        for(int i=0;i<strs.size();i++)
        {
            if(!visited[i] and similar(strs[index],strs[i]))
            {
                dfs(i,strs,visited);
            }
        }
    }
    
public:
    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size(),count=0;
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                dfs(i,strs,visited);
                count++;
            }
        }
        return count;
    }
};