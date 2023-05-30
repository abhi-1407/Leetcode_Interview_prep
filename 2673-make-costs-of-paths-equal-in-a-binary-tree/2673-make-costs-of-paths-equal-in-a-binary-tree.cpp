class Solution {
    int helper(int index,int n,vector<int> &cost,int &ans)
    {
        if(index>n)
            return 0;
        int lidx=helper(2*index,n,cost,ans);
        int ridx=helper(2*index+1,n,cost,ans);
        ans+=abs(lidx-ridx);
        return max(lidx,ridx)+cost[index-1];
    }
public:
    int minIncrements(int n, vector<int>& cost) {
        int ans=0;
        helper(1,n,cost,ans);
        return ans;
    }
};