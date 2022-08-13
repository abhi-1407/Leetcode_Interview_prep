class Solution {
    void reverse(vector<int> &arr,int i,int j)
    {
        while(i<j)
        {
            swap(arr[i++],arr[j--]);
        }
    }
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        reverse(nums,0,n-k-1);
        reverse(nums,n-k,n-1);
        reverse(nums,0,n-1);    
        
    }
};