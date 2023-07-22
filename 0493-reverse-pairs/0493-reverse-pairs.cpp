class Solution {
    int merge(vector<int> &nums,int low,int mid,int high)
    {
        int l=low,r=mid+1,count=0;
        while(l<=mid)
        {
            while(r<=high && nums[l]>(long)2*nums[r])
            {
                r++;
            }
            count+=(r-(mid+1));
            l++;
        }
        l=low,r=mid+1;
        vector<int> temp;
        while(l<=mid && r<=high)
        {
            if(nums[l]<=nums[r])
            {
                temp.push_back(nums[l]);
                l++;
            }
            else
            {
                temp.push_back(nums[r]);
                r++;
            }
        }
        while(l<=mid)
        {
            temp.push_back(nums[l]);
            l++;
        }
        while(r<=high)
        {
            temp.push_back(nums[r]);
            r++;
        }
        int index=0;
        for(int i=low;i<=high;i++)
        {
            nums[i]=temp[index++];
        }
        return count;
    }
    
    int mergeSort(vector<int> &nums,int low,int high)
    {
        if(low<high)
        {
            int mid=(low+high)/2;
            int count=mergeSort(nums,low,mid);
            count+=mergeSort(nums,mid+1,high);
            count+=merge(nums,low,mid,high);
            return count;
        }
        return 0;
    }
    
public:
    int reversePairs(vector<int>& nums) {
        
        return mergeSort(nums,0,nums.size()-1);   
    }
};


