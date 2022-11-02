class Solution {
public:
/* since we are using a simple queue so if we ignore this line we'll need to use a pq as visited the same word at a later stage would mean more no of steps */
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> dump(bank.begin(),bank.end()),visited;
        queue<pair<int,string>> q;
        q.push({0,start});
        char available[]={'A','C','G','T'};
        visited.insert(start);
        while(!q.empty())
        {
            int n=q.size();
            while(n--)
            {
                string current=q.front().second;
                int steps=q.front().first;
                q.pop();
                if(current==end)
                    return steps;
                for(int i=0;i<8;i++)
                {
                    string curr=current;
                    for(int j=0;j<4;j++)
                    {
                        curr[i]=available[j];
                        if(dump.find(curr)!=dump.end())
                        {
                            if(visited.find(curr)==visited.end())
                            {
                                q.push({steps+1,curr});
                                visited.insert(curr);
                            }                        
                            
                        }
                    }   
                    
                }                
            } 
        }
        return -1;
    }
};