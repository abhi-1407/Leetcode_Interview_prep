class Solution {
    private:
    vector<int> nextSmaller(vector<int> &heights,int n)
    {
        stack<int> st;
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--)
        {
            int curr=heights[i];
            if(st.empty())
            {
                ans[i]=-1;
            }
            else 
            {
                while(!st.empty() && heights[st.top()]>=curr)
                    st.pop();
                if(!st.empty())
                    ans[i]=st.top();
                else
                    ans[i]=-1;
            }
            st.push(i);
        }
        return ans;
    }
    
    vector<int> prevSmaller(vector<int> &heights,int n)
    {
        stack<int> st;
        vector<int> ans(n);
        for(int i=0;i<n;i++)
        {
            int curr=heights[i];
            while(!st.empty() && heights[st.top()]>=curr)
                st.pop();
            if(st.empty())
                ans[i]=-1;
            else
                ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n=heights.size();
        vector<int> ns(n);
        vector<int> ps(n);
        ns=nextSmaller(heights,n);
        ps=prevSmaller(heights,n);
        int maxAr=INT_MIN;
        for(int i=0;i<heights.size();i++)
        {
            int a=ps[i];
            int b=ns[i];
            if(b==-1)
                b=n;
            int area=(b-a-1)*heights[i];
            maxAr=max(area,maxAr);         
            
        }
        return maxAr;
        
    }
};