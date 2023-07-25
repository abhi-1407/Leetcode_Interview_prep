/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
    int left(int target,MountainArray &mountainArr,int l,int r)
    {
        int ans=-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            int ele=mountainArr.get(mid);
            if(ele==target)
            {
                ans=mid;
                r=mid-1;
            }
            else if(ele > target)
            {
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;
    }
    int right(int target,MountainArray &mountainArr,int l,int r)
    {
        int ans=-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            int ele=mountainArr.get(mid);
            if(ele==target)
            {
                ans=mid;
                r=mid-1;
            }
            else if(ele > target)
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return ans;
    }
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int size=mountainArr.length();
        int l=0,r=size-1,peak=0;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            int ele1=mountainArr.get(mid);
            int ele2=INT_MAX,ele3=INT_MAX;
            if(mid-1>=0)
            ele2=mountainArr.get(mid-1);
            if(mid+1<size)
            ele3=mountainArr.get(mid+1);
            if(ele1>ele2 && ele1>ele3)
            {
                peak=mid;
                break;
            }
            else if(ele1<ele2)
            {
                r=mid-1;
            }
            else if(ele1<ele3)
            {
                l=mid+1;
            }
        }
        int ans=0;
        ans=left(target,mountainArr,0,peak);
        if(ans!=-1) 
            return ans;
        else 
            return right(target,mountainArr,peak+1,size-1);
    }
};