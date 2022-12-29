//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int N)
    {
        vector<int> deno= {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
        int coins=0,amount=N,index=deno.size()-1;
        vector<int> ans;
        while(amount>0 && index>=0)
        {
            if(deno[index]>amount)
                index--;
            else
            {
                int coins=amount/(deno[index]);
                for(int i=0;i<coins;i++)
                ans.push_back(deno[index]);
                amount=amount%(deno[index]);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends