class Solution {
public:
    int countPrimes(int n) {
        vector<int> visited(n+1,true);
        int count=0;
        for(int i=2;i<n;i++)
        {
            if(visited[i])
            {
                count++;
                for(int j=2*i;j<=n;j=j+i)
                {
                    visited[j]=false;
                }
            }
        }
        return count;
    }
};