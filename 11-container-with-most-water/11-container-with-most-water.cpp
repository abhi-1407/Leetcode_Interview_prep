class Solution {
public:
//     int maxArea(vector<int>& height) {
//         int l=0,r=height.size()-1;
//         int maxi=0;
//         while(l<r)
//         {
//             int l=min(height[l],height[r]);
//             int h=r-l+1;
//             int water=height*length;
//             maxi=max(maxi,water);        
//             if(height[l]<=height[r])
//         }
//         return maxi;
        
//     }
// };


int maxArea(vector<int> &height)
{
    int l=0,r=height.size()-1;
    int maxi=INT_MIN;
    while(l<r)
    {
        int h=min(height[l],height[r]);
        int len=r-l;
        int water=h*len;
        maxi=max(water,maxi);
        if(height[l]<=height[r])
            l++;
        else
            r--;
    }
    return maxi;
}
};