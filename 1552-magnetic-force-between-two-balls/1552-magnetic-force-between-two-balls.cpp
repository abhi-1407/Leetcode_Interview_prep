class Solution {
    bool helper(vector<int>& position,int mid,int m)
    {
        int prevBall=0;
        int count=1;
        for(int i=1;i<position.size();i++)
        {
            if(position[i]-position[prevBall] >= mid)
            {
                count++;
                prevBall=i;
            }
        }
        if(count<m)
                return false;
        return true;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int l=0,h=position[position.size()-1],ans=0;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(helper(position,mid,m))
            {
                ans=mid;
                l=mid+1;
            }
            else
            {
                h=mid-1;
            }
        }
        return ans;
    }
};