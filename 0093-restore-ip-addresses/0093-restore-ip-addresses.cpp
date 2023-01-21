class Solution {
    void helper(vector<string> &ans,string s,string temp,int dots,int index)
    {
        if(dots>4 || (index>=s.length() && dots<4))
            return;
        if(dots==4 && index>=s.length())
        {
            ans.push_back(temp.substr(0,temp.length()-1));//removing the last dot
            return;
        }
        for(int length=1;length<=3 && index+length<=s.length();length++)
        {
            string num=s.substr(index,length);
            if(num[0]=='0' && length!=1)
                continue;
            else if(stoi(num)<=255)
                helper(ans,s,temp+num+".",dots+1,index+length);
        }        
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        helper(ans,s,"",0,0);
        return ans;
    }
};