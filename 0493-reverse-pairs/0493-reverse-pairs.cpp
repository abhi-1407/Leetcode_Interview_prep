class Solution {
    int merge(vector<int> &nums,int low,int mid,int high)
    {
        int left=low,right=mid+1;
        int t2=mid+1;
        int count=0;
        for(int t1=low;t1<=mid;t1++)
        {
            while(t2<=high && nums[t1]>(double)2*nums[t2])
            {
                t2++;
            }
            count+=t2-(mid+1);
        }
        vector<int> temp;
        while(left<=mid && right<=high)
        {
            if(nums[left]<=nums[right])
            {
                temp.push_back(nums[left]);
                left++;
            }
            else
            {
                temp.push_back(nums[right]);
                right++;
            }
        }
        while(left<=mid)
        {
            temp.push_back(nums[left]);
            left++;
        }
        while(right<=high)
        {
            temp.push_back(nums[right]);
            right++;
        }
        int k=0;
        for(int i=low;i<=high;i++)
        {
            nums[i]=temp[k++];
        }
        return count;
    }
    int mergeSort(vector<int> &nums,int low,int high)
    {   
        int count=0;
        if(low<high)
        {
            int mid=(low+high)>>1;
            count+=mergeSort(nums,low,mid);
            count+=mergeSort(nums,mid+1,high);
            count+=merge(nums,low,mid,high);
        }
        return count;
    }
public:
    int reversePairs(vector<int>& nums) {
        int ans=mergeSort(nums,0,nums.size()-1);
        return ans;
    }
};