//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    int helper(int i,int j,int arr[],vector<vector<int>> &dp)
    {
        if(i==j)
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        int cost=INT_MAX;
        for(int k=i;k<j;k++)
        {
            int temp=arr[i-1]*arr[j]*arr[k]+helper(i,k,arr,dp)+helper(k+1,j,arr,dp);
            cost=min(cost,temp);
        }
        return dp[i][j]=cost;
    }
public:
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>> dp(N,vector<int>(N,-1));
        return helper(1,N-1,arr,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends