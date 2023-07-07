class Solution {
    int helper(int k,string answerKey,char ch)
    {
        int j=0,i=0,maxi=0;
        while(j<answerKey.length())
        {
            if(answerKey[j]!=ch)
            {
                k--;
                while(k<0)
                {
                    if(answerKey[i]!=ch)
                        k++;
                    i++;
                }
            }   
            maxi=max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(helper(k,answerKey,'T'),helper(k,answerKey,'F'));
    }
};