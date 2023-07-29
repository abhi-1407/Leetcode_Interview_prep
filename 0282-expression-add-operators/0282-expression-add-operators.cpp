class Solution {
    void helper(vector<string> &ans,int index,int target,string temp,long prev,long sum,string &num)
    {
        if(index==num.size())
        {
            if(sum==target)
            {
                ans.push_back(temp);
            }
            return;
        }
        long val=0;
        string tempnum="";
        for(int i=index;i<num.length();i++)
        {
            if(i>index && num[index]=='0')
                break;
            tempnum+=num[i];
            val=val*10+num[i]-'0';
            if(index==0)
            {
                helper(ans,i+1,target,to_string(val),val,val,num);
            }
            else
            {
                helper(ans,i+1,target,temp+'+'+tempnum,val,sum+val,num);
                helper(ans,i+1,target,temp+'-'+tempnum,-val,sum-val,num);
                helper(ans,i+1,target,temp+'*'+tempnum,prev*val,sum-prev+(prev*val),num);
            }
        }
    }
public:
    vector<string> addOperators(string num, int target) {
        string temp="";
        vector<string> ans;
        helper(ans,0,target,"",0,0,num);
        return ans;
    }
};