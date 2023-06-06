class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int diff=arr[1]-arr[0];
        for(int i=1;i<arr.size()-1;i++)
        {
            int tempdiff=arr[i+1]-arr[i];
            if(tempdiff!=diff)
                return false;
        }
        return true;
    }
};