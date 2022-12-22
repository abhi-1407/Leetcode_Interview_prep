class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int count=0;
        unordered_map<int,int> mpp;
        for(auto it:tasks)
        {
            mpp[it]++;
            count=max(count,mpp[it]);
        }
        int ans=(count-1)*(n+1);
        for(auto it:mpp)
        {
            if(count==it.second)
                ans++;
        }
        return max(ans,(int)tasks.size());
    }
};