class Solution {
public:
    string frequencySort(string s) {
        unordered_map<int,int> mpp;
        vector<pair<int,char>>p;
        for(auto it:s)
        {
            mpp[it]++;
        }
        for(auto it:mpp)
        {
            p.push_back({it.second,it.first});
        }
        sort(p.begin(),p.end(),greater<pair<int,char>>());
        int i=0;
        for(auto it:p)
        {
            char ch=it.second;
            int len=it.first;
            while(len--)
            s[i++]=ch;
        }
        return s;       
        
    }
};