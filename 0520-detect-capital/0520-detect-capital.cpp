class Solution {
public:
    bool detectCapitalUse(string word) {
        bool caps,lower,first,flag=true;
        for(auto it:word)
        {
            if((it>='A' && it<='Z'))
            {
                cout<<"1"<<endl;
                flag=false;
                break;
            }
        }
        if(flag)
            caps=true;
        else
            caps=false;
        flag=true;
        for(auto it:word)
        {
            if((it>='a' && it<='z'))
            {
                cout<<"2"<<endl;
                flag=false;
                break;
            }
        }
        if(flag)
            lower=true;
        else
            lower=false;
        
        
        
        if(word[0]>='A' && word[0]<='Z')
        {
            flag=true;
            for(int i=1;i<word.size();i++)
            {
                if((word[i]>='A' && word[i]<='Z'))
                {
                    cout<<"3"<<endl;
                    flag=false;
                break;
                }
            }
        }
        if(flag)
            first=true;
        else
            first=false;
        return (first||caps||lower);
        
    }
};