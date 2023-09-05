class Solution {
public:vector<int> t;
    long long int d(int i,vector<vector<int>> &a,vector<long long int> &dp)
    {
        if(i>a.size()-1) return 0;
        if(dp[i]!=-1) return dp[i];

        int tg=lower_bound(t.begin(),t.end(),a[i][1])-t.begin();

        long long int p=a[i][2]+a[i][1]-a[i][0]+d(tg,a,dp);
        long long int np=d(i+1,a,dp);

        return dp[i]=max(p,np);
    }

    long long maxTaxiEarnings(int n, vector<vector<int>>& a) {
         int m=a.size();
        sort(a.begin(),a.end());

        vector<long long int> dp(m+1,-1);

        for(auto i : a)
        t.push_back(i[0]);

        return d(0,a,dp);
    }
};