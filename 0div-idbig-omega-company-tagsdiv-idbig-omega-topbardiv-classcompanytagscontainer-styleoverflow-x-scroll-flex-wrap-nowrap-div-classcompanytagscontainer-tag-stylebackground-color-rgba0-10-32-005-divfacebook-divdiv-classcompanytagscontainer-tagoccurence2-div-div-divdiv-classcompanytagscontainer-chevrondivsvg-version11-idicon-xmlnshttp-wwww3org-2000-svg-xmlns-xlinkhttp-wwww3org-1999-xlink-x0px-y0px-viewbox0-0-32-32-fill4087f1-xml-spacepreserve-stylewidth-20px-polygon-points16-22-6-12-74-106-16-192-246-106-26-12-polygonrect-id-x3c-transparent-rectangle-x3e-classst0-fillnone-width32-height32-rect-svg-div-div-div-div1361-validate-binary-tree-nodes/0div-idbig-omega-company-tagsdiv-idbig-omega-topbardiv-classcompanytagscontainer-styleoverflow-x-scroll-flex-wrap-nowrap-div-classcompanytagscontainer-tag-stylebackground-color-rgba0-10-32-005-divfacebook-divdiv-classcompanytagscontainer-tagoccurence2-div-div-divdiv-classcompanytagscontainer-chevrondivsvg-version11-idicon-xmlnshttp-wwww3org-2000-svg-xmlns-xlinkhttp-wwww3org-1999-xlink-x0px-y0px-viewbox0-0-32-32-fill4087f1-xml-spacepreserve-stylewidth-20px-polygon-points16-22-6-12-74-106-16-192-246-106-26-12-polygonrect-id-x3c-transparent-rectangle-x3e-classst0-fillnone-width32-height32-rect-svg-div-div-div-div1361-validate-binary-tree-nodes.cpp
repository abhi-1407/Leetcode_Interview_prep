class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        unordered_map<int,vector<int>> mpp;
        vector<int> indegree(n,0);
        for(int i=0;i<leftChild.size();i++)
        {
            if(leftChild[i]!=-1)
            {
                mpp[i].push_back(leftChild[i]);
                indegree[leftChild[i]]++;
            }
            if(rightChild[i]!=-1)
            {
                mpp[i].push_back(rightChild[i]);
                indegree[rightChild[i]]++;
            }
        }
        int count=0;
        queue<int> q;
        for(int i=0;i<indegree.size();i++)
        {
            if(indegree[i]>1)
                return false;
            if(indegree[i]==0)
            {
                count++;
                q.push(i);
            }
        }
        if(count>1)
            return false;
        vector<bool> visited(n,false);
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            visited[it]=true;
            for(auto i:mpp[it])
            {
                indegree[i]--;
                if(indegree[i]==0)
                    q.push(i);
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