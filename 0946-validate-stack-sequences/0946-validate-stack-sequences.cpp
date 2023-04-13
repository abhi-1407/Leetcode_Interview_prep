class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int l=0,i=0;
        stack<int> st;
        while(i<popped.size())
        {
            while(i<pushed.size())
            {
                st.push(pushed[i]);
                    i++;
                if(st.top()==popped[l])
                    break;
                
            }
            while(!st.empty() && st.top()==popped[l])
            {
                st.pop();
                l++;
            }
        }
        return st.size()==0 ? true: false;
        
    }
};