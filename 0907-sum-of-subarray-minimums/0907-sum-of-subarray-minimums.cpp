/* First we'll maintain two arrays left and right which will help figure out the count of smaller elements to the left and right of an element in an array */
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        int MOD=pow(10,9)+7;
        vector<int> left(n),right(n);
        stack<int> st1;
        st1.push(0);
        left[0]=1;
        for(int i=1;i<n;i++)
        {
            while(!st1.empty() && arr[i] <= arr[st1.top()])
            {
                st1.pop();
            }
            if(st1.empty())
            {
                left[i]=i+1;
            }
            else
            {
                left[i]=i-st1.top();
            }
            st1.push(i);
        }
        stack<int> st2;
        right[n-1]=1;
        st2.push(n-1);
        for(int i=n-2;i>=0;i--)
        {
            while(!st2.empty() && arr[i] < arr[st2.top()])
            {
                st2.pop();
            }
            if(st2.empty())
            {
                right[i]=n-i;
            }
            else
            {
                right[i]=st2.top()-i;
            }
            st2.push(i);
        }
        int res = 0;
        for(int i=0; i<n; i++)
        {
            long long prod = (left[i]*right[i])%MOD;
            prod = (prod*arr[i])%MOD;
            res = (res + prod)%MOD;
        }
        return res;
    }
};