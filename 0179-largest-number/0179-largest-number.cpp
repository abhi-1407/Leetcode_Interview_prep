/*simply check if the strings "2" "10" concatenated as "210" is greater or is "102" greater ,sort the strings on this basis*/
class Solution {
public:
    static bool compare(string a,string b)
    {
        return a+b>b+a;
    }
    string largestNumber(vector<int>& nums) {
        if(count(nums.begin(),nums.end(),0)==nums.size())//if there are only 0's
            return "0";
        vector<string> res;
        for(int x:nums)
        {
            string temp=to_string(x);
            res.push_back(temp);
        }
        sort(res.begin(),res.end(),compare);
        string ans="";
        for(auto it:res)
            ans+=it;
        return ans;
    }
};