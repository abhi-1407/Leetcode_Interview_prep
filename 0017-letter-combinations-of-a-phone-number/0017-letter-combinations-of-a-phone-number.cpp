class Solution {
    void helper(int index,string &digits,vector<string> &mpp,vector<string> &ans,string temp)
    {
        if(index==digits.size())
        {
            ans.push_back(temp);
            return;
        }
        string t=mpp[digits[index]-'0'];
        for(int i=0;i<t.length();i++)
        {
            helper(index+1,digits,mpp,ans,temp+t[i]);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size()==0)
            return ans;
        vector<string> mpp={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        helper(0,digits,mpp,ans,"");
        return ans;
    }
};