class Solution {
    bool isVowel(char c)
    {
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
    }
    int helper(string word,int k)
    {
        unordered_map<char,int> mpp;
        int i=0,j=0,count=0;
        while(j<word.size())
        {
            while(!isVowel(word[j]) && j<word.size())
            {
                i=j+1;
                j++;
                mpp.clear();
            }
            mpp[word[j]]++;
            while(mpp.size()>k)
            {
                if(mpp.count(word[i]))
                {
                    mpp[word[i]]--;
                    if(mpp[word[i]]==0)
                        mpp.erase(word[i]);   
                }
                i++;
            }
            count+=j-i+1;
            j++;
        }
        return count;
    }
public:
    int countVowelSubstrings(string word) {
        return helper(word,5)-helper(word,4);
    }
};