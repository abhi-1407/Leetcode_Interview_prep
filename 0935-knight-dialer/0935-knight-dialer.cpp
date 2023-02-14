class Solution {
    long long mod=pow(10,9)+7;
    long long helper(int i,int j,unordered_set<string> &visited,vector<vector<char>> &keypad,string &temp,int n,vector<vector<vector<int>>> &dp)
    {
        
        if(n==0)
        {
            if(visited.find(temp)!=visited.end())
                return 0;
            else
            {
                visited.insert(temp);
                return 1;
            }
        }
        if(dp[i][j][n]!=-1)
            return dp[i][j][n];
        vector<int> dr={1, 1, -1, -1, 2, 2, -2, -2};
        vector<int> dc={2, -2, 2, -2, 1, -1, 1, -1}; 
        long long count=0;
        for(int m=0;m<8;m++)
        {
            
            int newi=i+dr[m],newj=j+dc[m];
            if(newi<0 || newj<0 || newi>=4 || newj>=3 || keypad[newi][newj]=='*' || keypad[newi][newj]=='#')
                continue;
            else
            {
               temp.push_back(keypad[newi][newj]);
               count=(count+helper(newi,newj,visited,keypad,temp,n-1,dp))%mod;  
               temp.pop_back();
            }
                
        }
        return dp[i][j][n]=(count%mod);
    }
public:
    int knightDialer(int n) {
        string temp="";
        long long count=0;
        vector<vector<vector<int>>> dp(5,vector<vector<int>>(4,vector<int>(5001,-1)));
        unordered_set<string> visited;
        vector<vector<char>> keypad={{'1','2','3'},{'4','5','6'},{'7','8','9'},{'*','0','#'}};
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(keypad[i][j]!='*' && keypad[i][j]!='#')
                {
                    temp.push_back(keypad[i][j]);
                    count=(count+helper(i,j,visited,keypad,temp,n-1,dp))%mod;
                    temp.pop_back();
                }
                    
            }
        }
        
        return count%mod;
    }
};