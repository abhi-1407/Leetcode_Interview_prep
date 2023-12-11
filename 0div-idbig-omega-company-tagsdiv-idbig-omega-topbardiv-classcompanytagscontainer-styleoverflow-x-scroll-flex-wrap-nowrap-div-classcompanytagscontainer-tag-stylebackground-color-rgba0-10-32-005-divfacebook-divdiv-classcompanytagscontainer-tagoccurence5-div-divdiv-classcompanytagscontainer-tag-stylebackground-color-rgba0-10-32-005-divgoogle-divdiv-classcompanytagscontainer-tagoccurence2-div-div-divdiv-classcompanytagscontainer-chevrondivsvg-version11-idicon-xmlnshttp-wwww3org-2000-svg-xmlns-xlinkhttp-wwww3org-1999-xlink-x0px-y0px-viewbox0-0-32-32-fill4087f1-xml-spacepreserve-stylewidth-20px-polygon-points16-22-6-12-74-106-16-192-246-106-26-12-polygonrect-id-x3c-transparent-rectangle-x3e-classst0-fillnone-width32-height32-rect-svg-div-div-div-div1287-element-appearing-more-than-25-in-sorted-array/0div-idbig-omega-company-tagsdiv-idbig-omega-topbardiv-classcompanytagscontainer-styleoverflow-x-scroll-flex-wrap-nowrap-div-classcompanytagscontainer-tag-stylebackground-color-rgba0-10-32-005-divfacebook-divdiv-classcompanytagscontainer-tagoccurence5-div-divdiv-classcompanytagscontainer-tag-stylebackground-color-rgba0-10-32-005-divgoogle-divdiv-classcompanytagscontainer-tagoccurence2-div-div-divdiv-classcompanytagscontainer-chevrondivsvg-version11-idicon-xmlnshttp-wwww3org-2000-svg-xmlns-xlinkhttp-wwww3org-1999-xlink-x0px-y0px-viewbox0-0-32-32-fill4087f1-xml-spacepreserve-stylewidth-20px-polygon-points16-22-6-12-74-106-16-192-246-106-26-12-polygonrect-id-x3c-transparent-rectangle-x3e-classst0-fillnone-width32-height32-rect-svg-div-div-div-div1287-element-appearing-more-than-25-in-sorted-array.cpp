class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int len=arr.size()/4;
        for(int i=0;i<arr.size()-len;i++)
        {
            if(arr[i]==arr[i+len])
                return arr[i];
        }
        return -1;
        
    }
};