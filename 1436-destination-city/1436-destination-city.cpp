class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,int> mpp;
        unordered_set<string> st1;
        for(auto it:paths)
        {
            mpp[it[0]]++;
            st1.insert(it[0]);
            st1.insert(it[1]);
            
        }
        for(auto it:st1)
        {
            if(mpp.find(it)==mpp.end())
                return it;
        }
        return "";
    }
};