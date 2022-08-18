class Solution {
public:
    int minSetSize(vector<int>& arr) {
        priority_queue<pair<int,int>> pq;
        unordered_map<int,int> mpp;
        for(int i=0;i<arr.size();i++)
        {
            mpp[arr[i]]++;
        }
        for(auto it: mpp)
        {
            
            pq.push({it.second,it.first});
        }
        int n=arr.size(),m=arr.size();
        int count=0;
        while(!pq.empty()) 
        {
            auto it=pq.top();
            pq.pop();
            m-=it.first;
            count++;
            if(m<=(n/2))
                break;
        }
        return count;       
        
    }
};