class Solution {
public:
    int longestSubsequence(vector<int>& arr, int d) {
        int count=1;
unordered_map<int,int>mp;
for(auto x:arr)
{
if(mp.find(x-d)!=mp.end() )
{
mp[x]=mp[x-d]+1;
count=max(count,mp[x]);
}
else
{
mp[x]=1;
}
}
return count;
}
    
};