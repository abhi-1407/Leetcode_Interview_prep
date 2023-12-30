class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int size=words.size();
        if(size==1)
            return true;
        unordered_map<char,int> mpp;
        for(auto it:words)
        {
            for(auto i:it)
            {
                mpp[i]++;
            }
        }
        for(auto it:mpp)
        {
            if(it.second%size!=0)
                return false;
        }
        return true;
    }
};