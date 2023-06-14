class Twitter {
    vector<pair<int,int>> tweets;
    unordered_map<int,unordered_set<int>> followers;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets.push_back({userId,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        int count=10;
        vector<int> ans;
        for(int i=tweets.size()-1;i>=0 && count>0;i--)
        {
            if(tweets[i].first==userId || (followers[userId].count(tweets[i].first))>0)
            {
                ans.push_back(tweets[i].second);
                --count;
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */