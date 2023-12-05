class Solution {
public:
    string largestGoodInteger(string num) {
        int ans=-1;
        for(int i=0;i<num.length()-2;i++)
        {
            int temp=0;
            bool flag=true;
            for(int j=0;j<3;j++)
            {
                if(j==0)
                    temp=num[j+i]-'0';
                else if(j+i-1<0 || num[j+i]==num[j+i-1])
                    temp=temp*10+(num[j+i]-'0');
                else
                    flag=false;
            }
            if(flag && temp>=ans)
            {
                ans=temp;
            }
        }
        if(ans==0)
            return "000";
        return ans==-1?"":to_string(ans);
        
    }
};