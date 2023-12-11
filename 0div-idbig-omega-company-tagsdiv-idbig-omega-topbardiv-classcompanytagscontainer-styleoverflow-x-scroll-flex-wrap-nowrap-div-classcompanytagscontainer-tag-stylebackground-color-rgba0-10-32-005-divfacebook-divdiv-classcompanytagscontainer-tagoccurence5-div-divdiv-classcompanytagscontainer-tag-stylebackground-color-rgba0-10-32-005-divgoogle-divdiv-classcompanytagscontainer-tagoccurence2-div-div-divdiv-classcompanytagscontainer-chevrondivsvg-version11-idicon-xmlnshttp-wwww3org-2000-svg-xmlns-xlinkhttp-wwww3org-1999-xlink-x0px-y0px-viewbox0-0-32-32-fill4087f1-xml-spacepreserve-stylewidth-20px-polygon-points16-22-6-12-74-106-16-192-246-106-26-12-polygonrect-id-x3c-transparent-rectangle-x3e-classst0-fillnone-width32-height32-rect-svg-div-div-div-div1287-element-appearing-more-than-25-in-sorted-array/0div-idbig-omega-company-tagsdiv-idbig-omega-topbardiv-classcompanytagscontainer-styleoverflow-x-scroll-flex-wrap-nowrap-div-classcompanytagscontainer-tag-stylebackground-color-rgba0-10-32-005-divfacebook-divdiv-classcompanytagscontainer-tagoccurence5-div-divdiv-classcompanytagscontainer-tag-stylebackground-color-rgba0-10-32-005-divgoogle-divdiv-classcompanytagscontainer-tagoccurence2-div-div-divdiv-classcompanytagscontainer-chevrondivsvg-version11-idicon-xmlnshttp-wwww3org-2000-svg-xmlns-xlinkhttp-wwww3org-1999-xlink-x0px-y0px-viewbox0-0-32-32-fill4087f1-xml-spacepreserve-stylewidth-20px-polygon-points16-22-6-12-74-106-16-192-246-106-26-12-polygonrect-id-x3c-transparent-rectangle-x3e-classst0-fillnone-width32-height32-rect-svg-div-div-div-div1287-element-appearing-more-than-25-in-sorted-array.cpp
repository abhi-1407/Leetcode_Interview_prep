class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int,int> mpp;
        for(int i=0;i<arr.size();i++)
        {
            mpp[arr[i]]++;
        }
        for(auto it:mpp)
        {
            if(it.second>(arr.size()/4))
            {
                return it.first;
            }
        }
        return -1;
        
    }
};