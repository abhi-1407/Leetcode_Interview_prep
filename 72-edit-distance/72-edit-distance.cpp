class Solution {
//     int helper(string s1,string s2,int i,int j)
//     {
//         if(i<0)
//             return j+1;//which means that the first string is exhausted, so to convert   "" --->"c1,c2,.." we need to insert all the missing characters in s1;
//         if(j<0)
//             return i+1;//which means that the second string is exhausted, so to convert  "c1,c2,.." ---> "" we need to delete all the characters in s1;
//         if(s1[i]==s2[j])
//         {
//             return 0+helper(s1,s2,i-1,j-1);
//         }
//         int ins=1+helper(s1,s2,i,j-1);//as we have inserted one character so that has matched now 
//         int del=1+helper(s1,s2,i-1,j);//as we have removed a character from s1 then we move one step back
//         int rep=1+helper(s1,s2,i-1,j-1);//as we have replaced so that character has matched and we move both our pointers back
//         return min(ins,min(del,rep));//return min of all operations
        
//     }
    
    int helperDP(string s1,string s2)
    {
        int m=s1.length();
        int n=s2.length();
        int dp[m+1][n+1];
        for(int i=0;i<m+1;i++)
        {
            for(int j=0;j<n+1;j++)
            {
                if(i==0)
                dp[i][j]=j;
                else if(j==0)
                dp[i][j]=i;
                else if(s1[i-1]==s2[j-1])
                {
                  dp[i][j]=dp[i-1][j-1];
                }
                else
                {
                    int ins=1+dp[i][j-1];
                    int del=1+dp[i-1][j];
                    int rep=1+dp[i-1][j-1];
                    dp[i][j]=min(ins,min(del,rep));
                }
                    
            }
        }
        return dp[m][n];
    }
    
public:
    int minDistance(string word1, string word2) {
        return helperDP(word1,word2);
        
    }
};