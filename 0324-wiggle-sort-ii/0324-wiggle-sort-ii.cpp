class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp(n);
        sort(nums.begin(),nums.end());
        int j=n-1;
        int i=1;
        while(i<n)
        {
            temp[i]=nums[j];
            j--;
            i+=2;
        }
        i=0;
        while(i<n)
        {
            temp[i]=nums[j];
            i+=2;
            j--;
        }
        nums=temp;
    }
};