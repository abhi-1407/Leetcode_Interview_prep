class Solution {
    void helper(int index,string &digits,string s,vector<string> &ans,string mpp[])
    {
        if(index==digits.size())//base case
        {
            ans.push_back(s);
            return;
        }
        int num=digits[index]-'0';//find out the element from the mapping created
        string temp=mpp[num];//find the corresponding string
        for(int i=0;i<temp.size();i++)//iterate over till all the characters of the string
        {
            s.push_back(temp[i]);
            helper(index+1,digits,s,ans,mpp);
            s.pop_back();//backtracking
        }
        
    }
public:
    vector<string> letterCombinations(string digits) {
        string mpp[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string s="";
        vector<string> ans;
        if(digits=="")
            return ans;
        helper(0,digits,s,ans,mpp);
        return ans;
        
    }
};