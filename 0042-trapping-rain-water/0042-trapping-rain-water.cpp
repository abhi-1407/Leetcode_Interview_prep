class Solution {
public:
    int trap(vector<int>& height) {
         int n=height.size();
        vector<int> left,right(n);        
        left.push_back(height[0]);
        for(int i=1;i<n;i++)
        {
            left.push_back(max(height[i],left[i-1]));
            
        }
        right[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--)
        {
            right[i]=max(height[i],right[i+1]);
        }
        int ans=0;        
        for(int i=0;i<n;i++)
        {
            ans+=min(left[i],right[i])-height[i];
        }
        return ans;
    }
};