class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char,int> mpp;
        for(auto it:s){
            mpp[it]++;
        }
        priority_queue<pair<char,int>> pq;
        for(auto it:mpp){
            pq.push({it.first,it.second});
        }
        string ans = "";
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int size = min(it.second,repeatLimit);
            char ch = it.first;
            for(int i=0;i<size;i++){
                ans+= ch;
            }
            if(it.second - repeatLimit > 0){
                if(!pq.empty()){
                    auto i = pq.top();
                    pq.pop();
                    char ele2 = i.first;
                    int freq = i.second;
                    ans+=ele2;
                    freq--;
                    if(freq>0){
                        pq.push({ele2,freq});
                    }
                    pq.push({ch,it.second - repeatLimit});
                }else{
                    return ans;
                }
            }
        }
        return ans;
    }
};