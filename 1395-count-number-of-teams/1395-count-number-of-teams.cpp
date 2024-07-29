class Solution {
public:
    int dp[1001][4][3];
    int solve(int idx,int taken,int state,vector<int> &rating){
        int n=rating.size();
        if(taken==3) return 1;
        if(dp[idx][taken][state]!=-1) return dp[idx][taken][state];
        
        int ans=0,ele=rating[idx];
        for(int i=idx+1;i<n;i++){
            if(state==0){
                if(ele<rating[i]) ans+=solve(i,taken+1,1,rating);
                else if(ele>rating[i]) ans+=solve(i,taken+1,2,rating);
            }
            else if(state==1){
                if(ele<rating[i]) ans+=solve(i,taken+1,1,rating);
            }
            else if(state==2){
                if(ele>rating[i]) ans+=solve(i,taken+1,2,rating);
            }
        }
        return dp[idx][taken][state]=ans;
    }
    int numTeams(vector<int>& rating) {
        int ans=0,n=rating.size();
        memset(dp,-1,sizeof(dp));
        
        for(int i=0;i<=n-3;i++){
            ans+=solve(i,1,0,rating);
        }
        return ans;
    }
};