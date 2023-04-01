//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

int countDistinctSubstring(string s);

int main()
{
 int t,l,i,j;
 int temp;
    cin>>t;
 while(t--){
 string s;
  cin>>s;
  cout<<countDistinctSubstring(s)<<endl;

 }
}


// } Driver Code Ends


/*You are required to complete this method */

class Node{
    Node* links[26];
    
    public:
    void put(char c,Node *node)
    {
        links[c-'a']=node;
    }
    
    bool containsKey(char c)
    {
        return links[c-'a'];
    }
    
    Node *getNode(char c)
    {
        return links[c-'a'];
    }
};


int countDistinctSubstring(string s)
{
    //Your code here
    Node *root=new Node();
    int count=0;
    for(int i=0;i<s.length();i++)
    {
        Node* node=root;
        for(int j=i;j<s.length();j++)
        {
            if(!(node->containsKey(s[j])))
            {
                count++;
                node->put(s[j],new Node());
            }
            node=node->getNode(s[j]);
        }
    }
    return count+1;
}