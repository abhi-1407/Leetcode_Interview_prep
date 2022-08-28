class Solution {
    void helper(vector<string> &ans,int n,int open,int close,int index,string &temp)
    {
        if(index==2*n)
        {
            ans.push_back(temp);
            return;
        }
        if(open<n)
        {
            temp.push_back('(');
            helper(ans,n,open+1,close,index+1,temp);
            temp.pop_back();
        }
        if(close<open)
        {
            temp.push_back(')');
            helper(ans,n,open,close+1,index+1,temp);
            temp.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;
        helper(ans,n,0,0,0,temp);
        return ans;
        
    }
};