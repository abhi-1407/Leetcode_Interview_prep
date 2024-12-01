class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<double,int> mpp;
        for(int i=0;i<arr.size();i++){
            int ele = arr[i] * 2;
            if(mpp.find(ele) != mpp.end() || mpp.find(((double)arr[i]/2)) != mpp.end())
                return true;
            mpp[arr[i]] = i;
        }
        return false;
    }
};