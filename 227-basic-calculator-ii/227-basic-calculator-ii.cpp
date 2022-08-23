class Solution {
    bool isNum(char c)
    {
        if(c=='+' || c=='-' || c=='*' || c=='/'|| c==' ')
            return false;
        else
            return true;
    }
public:
    int calculate(string s) {
        stack<int> st;
        char prev_sign='+';
        s+='+';
        int curr=0;
        for(int i=0;i<s.length();i++)
        {
            
            if(isNum(s[i]))
            {
               
                curr=curr*10 + (s[i]-'0');
            }
            else if((s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/') || i==s.length()-1)
            {
               if(prev_sign=='+')
               {
                   st.push(curr);
               }
               else if(prev_sign=='-')
               {
                   st.push(-1*curr);
               }
               else if(prev_sign=='/')
               {
                   int a=st.top();
                   st.pop();
                   st.push(a/curr);
               }
               else if(prev_sign=='*')
               {
                   
                   int a=st.top();
                   st.pop();
                   st.push(a*curr);
               }
               curr=0;  
               prev_sign=s[i];
                         
            }
        }
        int ans=0;
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        return ans;
        
    }
};