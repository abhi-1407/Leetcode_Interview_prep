class Solution {
    int mod=pow(10,9)+7;//as we have to return ans in terms of mod
    /* donot store the previous character in a string as it would be really long */
    long long helper(int index,int n,char c,vector<vector<int>> &dp,unordered_map<char,int> &mpp)
    {
        if(index==n-1)//base case
        {
            return 1;
        }
        if(dp[index][mpp[c]]!=-1)//if that state is traversed then we need not calculate it again
            return dp[index][mpp[c]] %mod;
        long long int count=0;
        /* calls for different alphabets like a,e,i,o,u */
        if(c=='a')
        {
            count+=helper(index+1,n,'e',dp,mpp);
        }
        if(c=='e')
        {
            count+=helper(index+1,n,'a',dp,mpp);
            count+=helper(index+1,n,'i',dp,mpp);
        }
        if(c=='i')
        {
            count+=helper(index+1,n,'a',dp,mpp);
            count+=helper(index+1,n,'e',dp,mpp);
            count+=helper(index+1,n,'o',dp,mpp);
            count+=helper(index+1,n,'u',dp,mpp);
        }
        if(c=='o')
        {
            count+=helper(index+1,n,'i',dp,mpp);
            count+=helper(index+1,n,'u',dp,mpp);
        }
        if(c=='u')
        {
            count+=helper(index+1,n,'a',dp,mpp);
        }
        return dp[index][mpp[c]]=count%mod;
        
    }
    

public:
    int countVowelPermutation(int n) {
        long long  count=0;
        vector<vector<int>> dp(n+1,vector<int>(6,-1));
        unordered_map<char,int> mpp;/* map to map the characters with a value as ascii value wise they are far apart so
        we would require a lot of space */
        mpp['a']=1;
        mpp['e']=2;
        mpp['i']=3;
        mpp['o']=4;
        mpp['u']=5;              
        count+=helper(0,n,'a',dp,mpp);
        count+=helper(0,n,'e',dp,mpp);
        count+=helper(0,n,'i',dp,mpp);
        count+=helper(0,n,'o',dp,mpp);
        count+=helper(0,n,'u',dp,mpp);
        
        return (count)%(mod);
         
    }
};