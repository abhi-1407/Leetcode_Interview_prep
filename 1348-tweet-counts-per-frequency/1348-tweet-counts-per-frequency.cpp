class TweetCounts {
public:
    map<string ,vector<int>> m;
    
    TweetCounts() {
        
    }
    
    void recordTweet(string t, int time) {
        m[t].push_back(time);
        
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string t, int startTime, int endTime) {
        
        int k;
        if(freq=="minute")
        {
            k=60;
        }
        else if(freq=="hour")
            k=3600;
        else
            k=86400;
        
        int end=endTime-startTime;
        
        vector<int> ans(ceil((end+1)/(k*1.0)),0);
        for(int i=0;i<m[t].size();i++)
        {
            if((m[t][i]-startTime)<=end && (m[t][i]-startTime)>=0)
            {
                ans[ceil((m[t][i]-startTime+1)/(k*1.0))-1]++;
            }
        }
        return ans;
    }
};


/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */