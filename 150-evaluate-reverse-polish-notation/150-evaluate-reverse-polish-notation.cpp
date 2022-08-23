class Solution {
    bool isNum(string ch)
    {
        if(ch=="+" || ch=="-" || ch=="*" || ch=="/")
            return false;
        else
            return true;
    }
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.size()==0)
            return 0;
        stack<int> st;
        for(int i=0;i<tokens.size();i++)
        {
            if(isNum(tokens[i]))
                st.push(stoi(tokens[i]));
            else
            {
                int b=st.top();//just check the order in which they are multiplied i.e 13/5 not vice versa
                st.pop();
                int a=st.top();
                st.pop();
                int c;
                if(tokens[i]=="+")
                c=a+b;
                if(tokens[i]=="-")
                c=a-b;
                if(tokens[i]=="*")
                c=a*b;
                if(tokens[i]=="/")
                c=a/b;
                st.push(c);
            }
        }
        return st.top();
        
    }
};