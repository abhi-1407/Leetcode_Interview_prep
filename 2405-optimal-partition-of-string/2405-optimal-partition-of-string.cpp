class Solution {
public:
    int partitionString(string s) {
        unordered_map<char,int> mpp;
        int i=0,count=0;
        while(i<s.length())
        {
            if(mpp.find(s[i])==mpp.end())
            {
                mpp[s[i]]++;
            }
            else
            {
                mpp.clear();
                mpp[s[i]]++;
                count++;
            }
            i++;
        }
        if(mpp.size()>0)
            count++;
        return count;
    }
};