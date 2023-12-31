class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int maxi=-1;
        unordered_map<char, int> freq;
        unordered_map<char, int> index;
        for(char ch : s){
            freq[ch]++;
        }
        for(int i=0; i<s.size(); i++){
            index[s[i]]=i;
        }
        for(int i=0; i<s.size(); i++){
            if(freq[s[i]] > 1)
            maxi=max(maxi, index[s[i]]-i-1);
        }
        return maxi;
    }
};