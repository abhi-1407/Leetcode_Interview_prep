class Solution {
    bool isTrue(string s,int target)
    {
        if(s=="" && target==0)
            return true;        
        for(int i=0;i<s.length();i++)
        {
            string left = s.substr(0, i + 1);
            string right=s.substr(i + 1);
            int leftNum = stoi(left);
            if(isTrue(right, target - leftNum))
                return true;
        }
        return false;
    }
public:
    int punishmentNumber(int n) {
        int count=0;
        for(int i=1;i<=n;i++)
        {
            if(isTrue(to_string(i*i),i))
                count+=i*i;
        }
        return count;
    }
};