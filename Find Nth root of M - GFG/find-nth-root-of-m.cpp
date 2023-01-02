//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int NthRoot(int n, int m)
	{
	    // Code here.
	    long long x=m;
	    if(x==0||x==1)
            return x;
        long long l=0,h=x,ans=-1;
        while(l<=h)
        {
            long long mid=l+(h-l)/2;
            if(pow(mid,n)==x)
            {
                ans=mid;
                break;
            }
            else if(pow(mid,n)<x)
            {
                l=mid+1;
            }
            else 
            h=mid-1;
        }
        return ans;
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends