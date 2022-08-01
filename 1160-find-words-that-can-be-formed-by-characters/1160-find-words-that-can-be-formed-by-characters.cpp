class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int> mpp;
        for(int i=0;i<chars.length();i++)
        {
            mpp[chars[i]]++;
        }
        int ans=0;
        for(int i=0;i<words.size();i++)
        {
            unordered_map<char,int> temp;
            for(int j=0;j<words[i].size();j++)
            {
                temp[words[i][j]]++;
            }
            bool flag=true;
            for(auto it:temp)
            {
                if(mpp.find(it.first)==mpp.end())
                {
                    flag=false;
                    break;
                }
                else if(mpp.find(it.first)!=mpp.end())
                {
                    if(mpp[it.first]<temp[it.first])
                    {
                     flag=false;
                     break;   
                    }
                    
                }
            }
            if(flag)
                ans+=words[i].size();
        }
        return ans;
    }
};