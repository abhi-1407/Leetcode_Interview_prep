class Solution {
    unordered_map<string, int> um;
    vector<string> ans;
    bool dfs(string &str, int i)
    {
        if(i == str.size())
        {
            return true;
        }
        string tmp = "";
        for(int j = i; j < str.size(); j++)
        {
            tmp += str[j];
            if(j == str.size()-1 && i == 0)
                return false;
            else if(um.count(tmp))
            {
                if(dfs(str, j+1)) return true;
            }
        }
        return false;
    }
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        for(string &str : words)
            um[str]++;
        for(string &str : words)
        {
            if(dfs(str, 0))
                ans.push_back(str);
        }
        return ans;
    }
};