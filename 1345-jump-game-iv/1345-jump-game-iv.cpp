class Solution {
public:
    int minJumps(vector<int>& arr) {
        if(arr.size()==1)
            return 0;
        unordered_map<int,vector<int>> mpp;
        for(int i=0;i<arr.size();i++)
        {
            mpp[arr[i]].push_back(i);
        }
        queue<int> q;
        q.push(0);
        int jumps=0;
        int n=arr.size();        
        while(!q.empty())
        {
            jumps++;
            int s=q.size();
            for(int i=0;i<s;i++)
            {
                int j=q.front();
                q.pop();
                if(j-1>=0 && mpp.count(arr[j-1]))
                {
                  if(j-1==n-1)
                      return jumps;
                  q.push(j-1); 
                }
                if(j+1<n && mpp.count(arr[j+1]))
                {
                    if(j+1==n-1)
                        return jumps;
                    q.push(j+1);
                }
                if(mpp.count(arr[j]))
                {
                    for(auto it:mpp[arr[j]])
                    {
                        if(it!=j)
                        {
                            if(it==n-1)
                                return jumps;
                            else
                                q.push(it);
                        }
                    }
                }
                mpp.erase(arr[j]);
            }
        }
        return jumps;
        
    }
};