class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
//         int n=colors.length();
//         if(n==0 || n==1)
//           return 0;
//         char curr;
//         int cost=0;
//         int i=0,j=0;
//         priority_queue<int,vector<int>,greater<int>> pq;
//         while(i<n && j<n)
//         {
//             if(colors[i]==colors[j])
//             {
//                 pq.push(neededTime[j]);
//                 j++;
//             }
//             else
//             {
                
//                 if(pq.size()>1)
//                 {
                    
//                     while(pq.size()!=1)
//                     {
//                         cout<<pq.top()<<" ";
//                         cost+=pq.top();
//                         pq.pop();
//                     }
//                     pq.pop();
//                     i=j;
//                 }
//                 else if(pq.size()==1)
//                 {
//                     pq.pop();
//                     i=j;
//                 }
                                
//             }
//         }
//             if(pq.size()>1)
//             {
//                while(pq.size()!=1)
//                {
//                   cout<<pq.top()<<" ";
//                   cost+=pq.top();
//                   pq.pop();
//                }
//                pq.pop();
//             }            
        
//         return cost;
        int cost=0;
        for(int i=1;i<neededTime.size();i++)
        {
            if(colors[i]==colors[i-1])
            {
                if(neededTime[i]<neededTime[i-1])
                {
                    cost+=neededTime[i];
                    neededTime[i]=neededTime[i-1];
                }
                else
                {
                    cost+=neededTime[i-1];
                }
            }
        }
        return cost;
    }
};