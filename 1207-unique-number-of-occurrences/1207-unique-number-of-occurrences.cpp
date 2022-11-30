class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mpp1,mpp2;
        for(auto it:arr)
        {
            mpp1[it]++;
        }
        for(auto it:mpp1)
        {
            if(mpp2.count(it.second))
            {
                return false;
            }
            else
            {
                mpp2[it.second]++;
            }
        }
        return true;
    }
    
};