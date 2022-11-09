/* similar to a number representation like 51=5*10+1, here base is 26*/
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int res=0;
        for(auto it:columnTitle)
        {
            auto ele=it-'A'+1;
            res=res*26+ele;
        }
        return res;
    }
};