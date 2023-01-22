class Solution {
    bool palindrome(string s)
    {
        int i=0,j=s.length()-1;
        while(i<j)
        {
            if(s[i]!=s[j])
            return false;
            i++;
            j--;
        }
        return true;
    }
    void helper(vector<vector<string>> &ans,vector<string> &temp,int index,string &s)
    {
        if(index>=s.length())
        {
            ans.push_back(temp);
            return;
        }
        for(int length=1;length<=s.length() && length+index<=s.length();length++)
        {
            string t=s.substr(index,length);
            if(palindrome(t))
            {
                temp.push_back(t);
                helper(ans,temp,index+length,s);
                temp.pop_back();
            }
            
        }
        return;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        helper(ans,temp,0,s);
        return ans;
    }
};