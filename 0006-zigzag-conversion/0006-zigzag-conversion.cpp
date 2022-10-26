class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)
            return s;
        int n=s.size();
        bool down=false;
        vector<string> ans(numRows,"");
        int currRow=0;
        for(int i=0;i<n;i++)
        {
            ans[currRow].push_back(s[i]);
            if(currRow==0 || currRow==numRows-1)
                down=!down;
            if(down)
                currRow++;
            else
                currRow--;
        }
        string res="";
        for(int i=0;i<numRows;i++)
            res+=ans[i];
        return res;
    }
};