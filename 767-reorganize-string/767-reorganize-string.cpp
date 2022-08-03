class Solution {
public:
    string reorganizeString(string s) {
     map<char,int> mpp;
     for(int i=0;i<s.length();i++)
     {
         mpp[s[i]]++;
     }
     int maxi=INT_MIN;
     priority_queue<pair<int,char>> pq;
     for(auto i:mpp)
     {
         pq.push({i.second,i.first});
     }
     string ans="";
     if(pq.top().first> (s.length()+1)/2)
         return ans;
     
         
         while(pq.size()>1)
         {
             auto ele1=pq.top();
             pq.pop();
             auto ele2=pq.top();
             pq.pop();
             ans+=ele1.second;
             ans+=ele2.second;
             ele1.first--;
             ele2.first--;
             if(ele1.first>0)
                 pq.push(ele1);
             if(ele2.first>0)
                 pq.push(ele2);
                        
         }
         if(!pq.empty())//max of one element might be left if the string is of odd length
         {
             if(pq.top().first>1)// if more than one occurence of an element is left we can place them together now so return ""
             {
                 return "";
             }
             else
             {
                 ans+=pq.top().second;//else append it to the string
                 
             }
             
         }
         return ans;
              
    }
};