class Solution {
    void helper(int index,set<string> &st,string &s,int &maxi)
    {
        if(index==s.length())
        {
            if( (int) st.size() >maxi)
                maxi=(int)st.size();
            return;
        }
        for(int i=index;i<s.length();i++)
        {
            string temp=s.substr(index,i-index+1);
            if(st.find(temp)==st.end())
            {
                st.insert(temp);
                helper(i+1,st,s,maxi);
                st.erase(temp);
            }
        }
        
    }
public:
    int maxUniqueSplit(string s) {
        set<string> st;
        int maxi=INT_MIN;
        helper(0,st,s,maxi);
        return maxi;
    }
};