class Solution {
    void reverse(vector<int> &arr,int i,int j)//reversing function
    {
        while(i<j)
        {
            swap(arr[i++],arr[j--]);
        }
    }
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
/* if the no. of rotations are a lot then ultimately remainder of that value with n would be give the same ans*/
        k=k%n;
        reverse(nums,0,n-k-1); // reverse the part from 0 to k(from behind) 
        reverse(nums,n-k,n-1);//reverse the part from k(from behind) to n
        reverse(nums,0,n-1);//reverse the entire array
        
    }
};