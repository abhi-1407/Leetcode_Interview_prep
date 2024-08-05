class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> counter;//create an unordered map

        for(auto i: arr) {//fill the frequency
            counter[i]++;
        }

        for(auto i: arr) { 
            if(counter[i] == 1) k--;//if the frequency of string is 1  
            if(k == 0) return i;//when we found thekth distinct string
        }
        return "";//if not found

    }
};