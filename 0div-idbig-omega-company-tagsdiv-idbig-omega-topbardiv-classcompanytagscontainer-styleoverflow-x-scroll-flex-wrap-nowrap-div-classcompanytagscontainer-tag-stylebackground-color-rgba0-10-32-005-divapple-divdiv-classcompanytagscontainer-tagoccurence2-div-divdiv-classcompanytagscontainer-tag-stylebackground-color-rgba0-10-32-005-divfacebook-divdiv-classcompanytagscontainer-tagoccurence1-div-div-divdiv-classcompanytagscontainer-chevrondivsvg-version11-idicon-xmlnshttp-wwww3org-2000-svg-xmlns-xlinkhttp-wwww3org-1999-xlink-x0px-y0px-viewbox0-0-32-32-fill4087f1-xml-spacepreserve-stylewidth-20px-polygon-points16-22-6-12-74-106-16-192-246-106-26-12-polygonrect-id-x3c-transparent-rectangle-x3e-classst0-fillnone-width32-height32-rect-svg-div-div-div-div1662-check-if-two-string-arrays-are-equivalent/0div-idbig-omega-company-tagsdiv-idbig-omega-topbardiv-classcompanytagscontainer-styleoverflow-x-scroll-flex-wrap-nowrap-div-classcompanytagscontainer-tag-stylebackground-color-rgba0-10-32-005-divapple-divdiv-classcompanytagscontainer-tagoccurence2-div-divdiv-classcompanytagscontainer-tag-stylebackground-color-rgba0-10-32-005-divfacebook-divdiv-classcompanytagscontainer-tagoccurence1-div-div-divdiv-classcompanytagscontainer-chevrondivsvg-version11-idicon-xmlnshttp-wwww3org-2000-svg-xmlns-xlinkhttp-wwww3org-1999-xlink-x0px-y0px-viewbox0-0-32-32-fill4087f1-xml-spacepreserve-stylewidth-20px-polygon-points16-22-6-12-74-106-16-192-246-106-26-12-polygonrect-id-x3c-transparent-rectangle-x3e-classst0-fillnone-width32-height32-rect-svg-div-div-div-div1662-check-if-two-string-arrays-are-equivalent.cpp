class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string a="",b="";
        for(auto it:word1)
        {
            for(auto i:it)
            {
                a+=i;
            }
        }
        
        for(auto it:word2)
        {
            for(auto i:it)
            {
                b+=i;
            }
        }
        
        return a==b;
    }
};