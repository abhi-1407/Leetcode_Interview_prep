class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char,int> mpp;
        int count=0;
        for(int i=0;i<stones.size();i++)
        {
            mpp[stones[i]]++;
        }
        for(int i=0;i<jewels.size();i++)
        {
            if(mpp.find(jewels[i])!=mpp.end())
            {
                count+=mpp[jewels[i]];
            }
        }
        return count;
        
    }
};