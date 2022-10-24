class Solution {
    bool check(string a,string b)
    {
        char arr[26]={};
        for(auto it:a)
            arr[it-'a']++;
        for(auto it:b)
            arr[it-'a']++;
        for(auto it:arr)
        {
            if(it>1)
                return false;
        }
        return true;
    }
    
    int helper(int index,vector<string>& arr,string temp)
    {
        if(index==arr.size())
        {
            return temp.size();
        }
        int pick=INT_MIN;
        int notpick=helper(index+1,arr,temp);        
        if(check(temp,arr[index]))
        {
            pick=helper(index+1,arr,temp+arr[index]);
        }        
        return max(pick,notpick);
    }
public:
    int maxLength(vector<string>& arr) {
        return helper(0,arr,"");        
    }
};