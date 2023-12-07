class Solution {
public:
    string largestOddNumber(string num) {
        int index=0;
        bool flag=false;
        for(int i=num.length()-1;i>=0;i--)
        {
            if((num[i]-'0')%2!=0)
            {
                index=i;
                flag=true;
                break;
            }
        }
        return flag==false?"":num.substr(0,index+1);

    }
};