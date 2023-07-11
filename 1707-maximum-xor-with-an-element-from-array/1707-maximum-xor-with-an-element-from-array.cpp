 class Node{
     Node *links[2];
     bool flag=false;
     public:
     
     void setEnd()
     {
         flag=true;
     }
    
     bool getEnd()
     {
         return flag;
     }
        
     void insertNode(Node *temp,int val)
     {
         links[val]=temp;
     }
        
    Node *nextNode(int val)
    {
        return links[val];
    }
    
    bool nextNodeExists(int val)
    {
        return links[val]!=NULL;
    }
        
};
    
class Trie{
  Node *root;
  public:
    Trie()
    {
        root=new Node();
    }
    void insertBit(int val)
    {
        Node *temp=root;
        for(int i=31;i>=0;i--)
        {
            int bit=(val& (1<<i))==0?0:1;
            if(!(temp->nextNodeExists(bit)))
            {
                temp->insertNode(new Node(),bit);
            }
            temp=temp->nextNode(bit);
        }
    }
    
    int Maxival(int val)
    {
        int maxi=0;
        Node *temp=root;
        for(int i=31;i>=0;i--)
        {
            int bit=(val& (1<<i))==0?0:1;
            if(temp->nextNodeExists(!bit))
            {
                temp=temp->nextNode(!bit);
                maxi=maxi|(1<<i);
            }
            else
            {
                temp=temp->nextNode(bit);
            }
        }
        return maxi;
    }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Trie t;
        vector<pair<int,pair<int,int>>>oQ;
        sort(nums.begin(),nums.end());
        int n=queries.size();
        vector<int> ans(n,0);
        for(int i=0;i<n;i++)
        {
            int Xi=queries[i][0];
            int Mi=queries[i][1];
            oQ.push_back({Mi,{Xi,i}});
        }
        sort(oQ.begin(),oQ.end());
        int ind=0;
        for(int i=0;i<oQ.size();i++)
        {
            int index=oQ[i].second.second;
            int limit=oQ[i].first;
            int xi=oQ[i].second.first;
            while(ind<nums.size() && nums[ind]<=limit)
            {
                t.insertBit(nums[ind]);
                ind++;
            }
            if(ind==0)
            ans[index]=-1;
            else
            ans[index]=t.Maxival(xi);
        }
        return ans;
        
    }
};