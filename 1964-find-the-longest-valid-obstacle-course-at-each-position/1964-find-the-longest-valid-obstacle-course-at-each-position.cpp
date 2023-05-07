class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> lis;
        int n=obstacles.size();
        vector<int> ans(n,0);
        ans[0]=1;
        lis.push_back(obstacles[0]);
        for(int i=1;i<n;i++)
        {
            if(obstacles[i]>=lis.back())
            {
                lis.push_back(obstacles[i]);
                ans[i]=lis.size();
            }
            else
            {
                int pos=upper_bound(lis.begin(),lis.end(),obstacles[i])-lis.begin();
                lis[pos]=obstacles[i];
                ans[i]=pos+1;
            }
        }
        return ans;
        
    }
};