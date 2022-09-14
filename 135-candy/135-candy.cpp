class Solution {
public:
    int candy(vector<int>& A) {
        int n=A.size();
    vector<int> left(n,1), right(n,1);
    int ans=0;
    for(int i=1;i<n;i++)
    {
        if(A[i-1]<A[i])
        {
            left[i]=left[i-1]+1;
        }
    }
    for(int i=n-2;i>=0;i--)
    {
        if(A[i]>A[i+1])
        {
            right[i]=right[i+1]+1;
        }
    }
    for(int i=0;i<n;i++)
    {
        ans+=max(left[i],right[i]);
    }
    return ans;
    
        
    }
};