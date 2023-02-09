#define ll long long
class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_set<string> s[26];
        for(auto it:ideas)
        {
            s[it[0]-'a'].insert(it.substr(1));
        }
        ll ans=0;
        for(int i=0;i<26;i++)
        {
            for(int j=i+1;j<26;j++)
            {
                ll c1=0,c2=0;
                for(auto it:s[i])
                    c1+=(!s[j].count(it));
                for(auto it:s[j])
                    c2+=(!s[i].count(it));
                ans+=(c1*c2);
            }
        }
        return 2*ans;
    }
};