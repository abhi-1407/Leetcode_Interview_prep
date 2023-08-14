class Solution {

public:
   bool func(int idx,vector<int> &v, vector<int> &dp){
    int n=v.size();
    
    if(idx==n) return true;
    if(idx>n) return false;
    
    if(dp[idx]!=-1) return dp[idx];
    
    bool flag1 = false, flag2 = false, flag3 = false;

    if(idx+1<n && v[idx]==v[idx+1])                             flag1 = func(idx+2,v,dp);
    if(idx+2<n && v[idx]==v[idx+1] && v[idx]==v[idx+2])         flag2 = func(idx+3,v,dp);
    if(idx+2<n && v[idx]+1==v[idx+1] && v[idx+1]+1 == v[idx+2]) flag3 = func(idx+3,v,dp);
    
    return dp[idx] =  flag1 || flag2 || flag3 ;
}

bool validPartition(vector<int>& v) {
    vector<int> dp(v.size(),-1);
    return func(0,v,dp);
}
};