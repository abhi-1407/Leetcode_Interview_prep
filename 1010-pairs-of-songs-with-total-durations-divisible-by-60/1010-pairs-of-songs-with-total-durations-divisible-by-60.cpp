class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int> mpp;
        int count=0;
        for(int i=0;i<time.size();i++)
        {
            time[i]=time[i]%60;
        }
        for(auto it:time)
        {
            if(it==0)
            {
                count+=mpp[0];
            }
            else if(mpp.find(60-it)!=mpp.end())
            {
                count+=mpp[60-it];
            }
            mpp[it]++;
        }
        
        return count;
    }
};