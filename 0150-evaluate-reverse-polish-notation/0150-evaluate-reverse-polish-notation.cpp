class Solution {
    bool isOper(string ch)
    {
        if(ch=="+" || ch=="-" || ch=="*" || ch=="/")
            return true;
        else
            return false;
    }
    int arith(long long a,long long b,string s)
    {
        if(s=="+")
            return a+b;
        if(s=="-")
            return a-b;
        if(s=="*")
            return a*b;
        if(s=="/")
            return a/b;
        return -1;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long>st;
        for(auto it:tokens)
        {
            if(isOper(it))
            {
                long long a=st.top();
                st.pop();
                long long b=st.top();
                st.pop();
                long long ans=arith(b,a,it);
                st.push(ans);                
            }
            else
            {
                st.push(stoi(it));
            }
        }           
        return st.top();
    }
};