class Solution {
    vector<int> nextSmaller(int heights[],int n)
    {
        stack<int> st;
        vector<int> ans(n);
        st.push(-1);
        for(int i=n-1;i>=0;i--)
        {
            int curr=heights[i];
            while(st.top()!=-1&& heights[st.top()]>=curr)
            {
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
        
    }
    
    vector<int> prevSmaller(int heights[],int n)
    {
        stack<int> st;
        vector<int> ans(n);
        st.push(-1);
        for(int i=0;i<n;i++)
        {
            int curr=heights[i];
            while(st.top()!=-1 && heights[st.top()]>=curr)
            {
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);
        }
        return ans;        
    }
    int helper(int heights[],int n)
    {
        
        vector<int> ns(n);
        vector<int> ps(n);
        ns=nextSmaller(heights,n);
        ps=prevSmaller(heights,n);
        int maxAr=INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(ns[i]==-1)
            {
                ns[i]=n;
            }
            int b=ns[i]-ps[i]-1;
            maxAr=max(maxAr,b*heights[i]);
        }
        return maxAr;
        
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
       
        int n=matrix[0].size();
        int a[n];
        for(int i=0;i<matrix[0].size();i++)
           a[i]=matrix[0][i]-'0';
        int maxArea=helper(a,n);
        for(int i=1;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
               if((matrix[i][j]-'0')==1)
               {
                 a[j]+=1;                    
               }
               else
               {
                 a[j]=0;
               }
             }
            maxArea=max(maxArea,helper(a,n));
          }
  
        return maxArea;
    }
};