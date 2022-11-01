//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        queue<pair<int,int>>q;
        int mod=pow(10,5);
        vector<int> distance(mod,1e9);
        q.push({0,start});
        while(!q.empty())
        {
            int node=q.front().second;
            int steps=q.front().first;
            q.pop();
            steps=steps+1;//as it takes 1 step extra to reach this node
            for(auto it:arr)
            {
                int num=(it*node)%mod;
                if(distance[num] > steps)
                {
                    if(num==end)//no need for any further computations
                    return steps;
                    distance[num]=steps;
                    q.push({steps,num});
                }
            }
            
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends