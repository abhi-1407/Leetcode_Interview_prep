class Solution {
    int helper(string s,int k)
    {
        int freq[26]={0};
        for(int i=0;i<s.size();i++)
        {
            freq[s[i]-'a']++;           
        }
        int index=0;
        while(index<s.size() && freq[s[index]-'a']>=k)
        {
            index++;
        }
        if(index==s.size())//entire string can be taken
            return s.size();
        int left=helper(s.substr(0,index),k);
        while(index<s.size() && freq[s[index]-'a']<k)
        {
            index++;
        }
        int right=helper(s.substr(index,s.size()-1),k);
        return max(left,right);
    }
public:
    int longestSubstring(string s, int k) {
        return helper(s,k);             
  }
};