class Solution {
public:
    bool checkValidString(string s) {
        stack<int> open,star;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='*')
                star.push(i);
            else if(s[i]=='(')
                open.push(i);
            else
            {
                if(!open.empty())
                    open.pop();
                else if(!star.empty())
                    star.pop();
                else
                    return false;
            }
        }
        while(!open.empty()) // balance the open brackets
        {
            int index=open.top();
            open.pop();
            if(star.empty())
                return false;
            if(index< star.top())
                star.pop();
            else
                return false;
        }
        return true;
    }
};