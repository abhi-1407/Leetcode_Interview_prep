class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()<t.size())
            return "";
        unordered_map<char,int> mpp1,mpp2;
        for(auto it:t)
            mpp1[it]++;
        int size=mpp1.size();
        unordered_set<char> st;
        int ans=INT_MAX;
        int j=0,ai=INT_MAX,aj=INT_MAX;
        for(int i=0;i<s.size();i++)
        {
            mpp2[s[i]]++;
            if(mpp2[s[i]]==mpp1[s[i]])//once we have reached the desired freq of one char
                st.insert(s[i]);
            if(st.size()==size)//if there's a scope of deleting extra elements
            {
                while(mpp2[s[j]] > mpp1[s[j]])
                {
                    mpp2[s[j]]--;
                    j++;
                }
                if(i-j+1<ans)
                {
                    ans=i-j+1;
                    ai=i;
                    aj=j;
                }
            }
        }
        if(ai==INT_MAX)//if we weren't able to find the desired string
            return "";
        else
            return s.substr(aj,ai-aj+1);
    }
};