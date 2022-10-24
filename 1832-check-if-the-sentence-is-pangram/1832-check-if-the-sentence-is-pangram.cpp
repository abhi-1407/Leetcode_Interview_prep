class Solution {
public:
    bool checkIfPangram(string sentence) {
        char arr[26]={};
        for(auto it:sentence)
        arr[it-'a']++;
        for(auto it:arr)
        {
            if(it==0)
                return false;
        }
        return true;
    }
};