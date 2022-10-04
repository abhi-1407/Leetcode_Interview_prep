class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26,0);
        for(char ch:s)
        {
            freq[ch-'a']++;
        }
        unordered_set<int> seen;
        int ans=0;
        for(int i=0;i<26;i++)
        {
            while(freq[i] and seen.find(freq[i])!=seen.end())
            {
                freq[i]--;//reduce the freq
                ans++;//update the ans as we are dec the freq
            }
            seen.insert(freq[i]);//insert the updated frequency into the set
        }
        return ans;
    }
};