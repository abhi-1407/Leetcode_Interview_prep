class Solution {
public:
    vector<vector<long>> dp;
    long fun(int idx1,int prevIdx,int n,int m,vector<int>& arr1,vector<int>& arr2){
        if(idx1 == n) return 0;
        if(dp[idx1][prevIdx] != -1) return dp[idx1][prevIdx];  
        if(prevIdx == 0){
            int prevElement = (idx1 == 0) ? INT_MIN : arr1[idx1-1];
            int idx2 = upper_bound(arr2.begin(),arr2.end(),prevElement)-arr2.begin();
            long op1 = (prevElement<arr1[idx1]) ? fun(idx1+1,0,n,m,arr1,arr2):INT_MAX;
            long op2 = (idx2 == m) ? INT_MAX:1+fun(idx1+1,idx2+1,n,m,arr1,arr2);
            return dp[idx1][prevIdx] = min(op1,op2);
        }
        int prevElement=arr2[prevIdx-1];
        int idx2 = upper_bound(arr2.begin(),arr2.end(),prevElement)-arr2.begin();
        long op1 = (prevElement<arr1[idx1])? fun(idx1+1,0,n,m,arr1,arr2): INT_MAX;
        long op2 = (idx2==m)? INT_MAX: 1+fun(idx1+1,idx2+1,n,m,arr1,arr2);
        return dp[idx1][prevIdx]=min(op1,op2);
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size(),m=arr2.size();
        sort(arr2.begin(),arr2.end());
        dp = vector<vector<long>> (n+1,vector<long>(m+1,-1));
        long res = fun(0,0,n,m,arr1,arr2);
        return res >= INT_MAX?-1:(int)res;
    }
};