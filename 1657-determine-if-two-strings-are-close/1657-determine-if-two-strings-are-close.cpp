class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> v1(26,0),v2(26,0),v3(26,0),v4(26,0);
        for(auto it:word1)
        {
            v1[it-'a']++;
            v2[it-'a']=1;
        }  
        for(auto it:word2)
        {
            v3[it-'a']++;
            v4[it-'a']=1;
        } 
        sort(v1.begin(),v1.end());
        sort(v3.begin(),v3.end());
        return v1==v3 && v2==v4;
    }
};
