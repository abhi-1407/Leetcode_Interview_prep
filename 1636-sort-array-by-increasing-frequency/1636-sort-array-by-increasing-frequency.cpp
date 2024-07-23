class Solution {
public:
bool static comp(pair<int,int>p1,pair<int,int>p2){
    if(p1.second!=p2.second) return p1.second<p2.second;
    return p1.first>p2.first;
}
    vector<int> frequencySort(vector<int>& nums) {
        int freq[210]; //210 is not a magic number,it just take care of all the elements in the range;
        int n=nums.size();
      //initializing freq to 0
        for(int i=0;i<210;i++){
            freq[i]=0;
        }
    //populating with frequency corresponding to each element;
        for(int i=0;i<n;i++){
            freq[nums[i]+101]++;
        }
    //making pair of elements and its frequency;
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({nums[i],freq[nums[i]+101]});
        }

        sort(v.begin(),v.end(),comp);
  //extracting sorted value from v to return;
        vector<int>ans;
        for(int i=0;i<n;i++){
            ans.push_back(v[i].first);
        }
        return ans;
    }
};