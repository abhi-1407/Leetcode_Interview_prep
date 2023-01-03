class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> temp(10001,0);
        for(int i=0;i<arr.size();i++)
        {
            temp[arr[i]]=1;
        }
        for(int i=1;i<10001;i++)
        {
            if(temp[i]==0)
            {
                --k;
                if(k==0)
                return i;
            }
        }
        return -1;
    }
};