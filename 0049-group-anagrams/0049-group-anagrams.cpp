class Solution {
    string helper(string temp)
    {
        int t[26]={0};
        string tt="";
        for(auto it:temp)
        {
            t[it-'a']++;            
        }
        for(int i=0;i<26;i++)
        {
            if(t[i]>0)
            {
                for(int j=0;j<t[i];j++)
                {
                  tt+=(i+'a');
                }   
            }
        }
        return tt;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mpp;//char and its corresponding freq
        for(auto it:strs)
        {
            string new_temp=helper(it);
            mpp[new_temp].push_back(it);
        }
        vector<vector<string>> ans;
        for(auto it:mpp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};