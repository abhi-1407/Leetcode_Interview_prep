class Solution {
    bool isPalindrome(string &s ,int i,int j)
    {        
        while(i<j)
        {
            if(s[i++]!=s[j--])
                return false;
        }
        return true;
    }
    
    void helper(vector<string> &temp,vector<vector<string>> &ans,int index,string s)
    {
        if(index==s.length())
        {
             ans.push_back(temp); 
             return; 
        }
        for(int i=index;i<s.length();i++)
        {          
            if(isPalindrome(s,index,i))
            {
                temp.push_back(s.substr(index,i-index+1));
                helper(temp,ans,i+1,s);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
         vector<string> temp;
         vector<vector<string>> ans;
         helper(temp,ans,0,s);
         return ans;
    }
};