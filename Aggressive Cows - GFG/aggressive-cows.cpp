//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    bool isPossible(int mid,int n ,int k,vector<int> &stalls)
    {
        k=k-1;
        int index=1,prev=0;
        while(index<n && k)
        {
            if(stalls[index]-stalls[prev]>=mid)
            {
                prev=index;
                k--;
            }
            index++;
        }
        return k==0;
    }
public:

    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(),stalls.end());
        int ans=-1;
        int low=0,high=stalls[n-1]-stalls[0];
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(isPossible(mid,n,k,stalls))
            {
                ans=mid;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends