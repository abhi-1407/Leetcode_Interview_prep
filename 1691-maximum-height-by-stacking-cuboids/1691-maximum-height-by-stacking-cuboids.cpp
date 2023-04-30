class Solution {
    
    static bool cmp(vector<int> &a,vector<int> &b)
    {
        if(a[0]==b[0])
        {
            if(a[1]==b[1])
                return a[2]>b[2];
            else
                return a[1]>b[1];
        }
        return a[0]>b[0];
        
    }
    int helper(vector<vector<int>>& cuboids,int index,int prev,vector<vector<int>> &dp)
    {
        if(index>=cuboids.size())
            return 0;
        if(dp[index][prev+1]!=-1)
            return dp[index][prev+1];
        int pick=INT_MIN,notpick=INT_MIN;
        if((prev==-1)||(cuboids[index][1]<=cuboids[prev][1] && cuboids[index][2]<=cuboids[prev][2]))
        {
            pick=cuboids[index][0]+helper(cuboids,index+1,index,dp);
        }
        notpick=helper(cuboids,index+1,prev,dp);
        return dp[index][prev+1]=max(pick,notpick);
    }
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        for(int i=0;i<cuboids.size();i++)
        {
            sort(cuboids[i].begin(),cuboids[i].end(),greater<int>());
        }
        sort(cuboids.begin(),cuboids.end(),cmp);
        for(auto it:cuboids)
        {
            cout<<it[0]<<" "<<it[1]<<" "<<it[2]<<endl;
        }
        vector<vector<int>> dp(cuboids.size()+1,vector<int>(cuboids.size()+1,-1));
        return helper(cuboids,0,-1,dp);
    }
};