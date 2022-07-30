/* Initial Solution 1- Uses O(nklogk) where k is the size of the the word and n are the no of words */
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map<string,vector<string>>mpp;
        int n=strs.size();
        for(int i=0;i<n;i++)
        {
            string temp=strs[i];
            sort(temp.begin(),temp.end());
            mpp[temp].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto it:mpp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};

